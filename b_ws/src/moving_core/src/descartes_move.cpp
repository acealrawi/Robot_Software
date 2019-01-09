#include <ros/ros.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <actionlib/client/simple_action_client.h>
#include <descartes_moveit/ikfast_moveit_state_adapter.h>
#include <descartes_trajectory/axial_symmetric_pt.h>
#include <descartes_trajectory/cart_trajectory_pt.h>
#include <descartes_planner/dense_planner.h>
#include <descartes_utilities/ros_conversions.h>

std::vector<descartes_core::TrajectoryPtPtr> makePath();

/**
 * Sends a ROS trajectory to the robot controller
 */
bool executeTrajectory(const trajectory_msgs::JointTrajectory& trajectory);

int main(int argc, char** argv)
{
  // Initialize ROS
  ros::init(argc, argv, "descartes_move");
  ros::NodeHandle nh;

  ros::AsyncSpinner spinner (1);
  spinner.start();

  descartes_core::RobotModelPtr model (new descartes_moveit::IkFastMoveitStateAdapter());

  const std::string robot_description = "robot_description";

  const std::string group_name = "manipulator";

  const std::string world_frame = "/world";

  const std::string tcp_frame = "tool0";

  if (!model->initialize(robot_description, group_name, world_frame, tcp_frame))
  {
    ROS_INFO("Could not initialize robot model");
    return -1;
  }

  model->setCheckCollisions(true); 

  std::vector<descartes_core::TrajectoryPtPtr> points = makePath();

  descartes_planner::DensePlanner planner;

  if (!planner.initialize(model))
  {
    ROS_ERROR("Failed to initialize planner");
    return -2;
  }

  if (!planner.planPath(points))
  {
    ROS_ERROR("Could not solve for a valid path");
    return -3;
  }

  std::vector<descartes_core::TrajectoryPtPtr> result;
  if (!planner.getPath(result))
  {
    ROS_ERROR("Could not retrieve path");
    return -4;
  }

  std::vector<std::string> names;
  nh.getParam("controller_joint_names", names);

  trajectory_msgs::JointTrajectory joint_solution;
  joint_solution.joint_names = names;

  const static double default_joint_vel = 0.5; // rad/s
  if (!descartes_utilities::toRosJointPoints(*model, result, default_joint_vel, joint_solution.points))
  {
    ROS_ERROR("Unable to convert Descartes trajectory to joint points");
    return -5;
  }

  if (!executeTrajectory(joint_solution))
  {
    ROS_ERROR("Could not execute trajectory!");
    return -6;
  }

  ROS_INFO("Done!");
  return 0;
}

descartes_core::TrajectoryPtPtr makeCartesianPoint(const Eigen::Affine3d& pose, double dt)
{
  using namespace descartes_core;
  using namespace descartes_trajectory;

  return TrajectoryPtPtr( new CartTrajectoryPt( TolerancedFrame(pose), TimingConstraint(dt)) );
}

descartes_core::TrajectoryPtPtr makeTolerancedCartesianPoint(const Eigen::Affine3d& pose, double dt)
{
  using namespace descartes_core;
  using namespace descartes_trajectory;
  return TrajectoryPtPtr( new AxialSymmetricPt(pose, M_PI / 12.0, AxialSymmetricPt::Z_AXIS, TimingConstraint(dt)) );
}

std::vector<descartes_core::TrajectoryPtPtr> makePath()
{
  const static double step_size = 0.02;
  const static int num_steps = 10;
  const static double time_between_points = 0.5;

  EigenSTL::vector_Affine3d pattern_poses;
  for (int i = -num_steps / 2; i < num_steps / 2; ++i)
  {
    // Create a pose and initialize it to identity
    Eigen::Affine3d pose = Eigen::Affine3d::Identity();
    // set the translation (we're moving along a line in Y)
    pose.translation() = Eigen::Vector3d(-0.3, -0.2, -0.07);

    
    // set the orientation. By default, the tool will be pointing up into the air when we usually want it to
    // be pointing down into the ground.
    pose *= Eigen::AngleAxisd(M_PI * 0.5, Eigen::Vector3d::UnitX()); // this flips the tool around so that Z is down
    pattern_poses.push_back(pose);
  }

  

  Eigen::Affine3d pattern_origin = Eigen::Affine3d::Identity();
  pattern_origin.translation() = Eigen::Vector3d(0.1, 0.2, 0.3);

  std::vector<descartes_core::TrajectoryPtPtr> result;
  for (const auto& pose : pattern_poses)
  {
    // This creates a trajectory that searches around the tool Z and let's the robot move in that null space
    descartes_core::TrajectoryPtPtr pt = makeTolerancedCartesianPoint(pattern_origin * pose, time_between_points);
    // This creates a trajectory that is rigid. The tool cannot float and must be at exactly this point.
    //  descartes_core::TrajectoryPtPtr pt = makeCartesianPoint(pattern_origin * pose, time_between_points);
    result.push_back(pt);
  }

  // Note that we could also add a joint point representing the starting location of the robot, or a joint point
  // representing the desired end pose of the robot to the front and back of the vector respectively.

  return result;
}

bool executeTrajectory(const trajectory_msgs::JointTrajectory& trajectory)
{
  // Create a Follow Joint Trajectory Action Client
  actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> ac ("joint_trajectory_action", true);
  if (!ac.waitForServer(ros::Duration(2.0)))
  {
    ROS_ERROR("Could not connect to action server");
    return false;
  }

  control_msgs::FollowJointTrajectoryGoal goal;
  goal.trajectory = trajectory;
  goal.goal_time_tolerance = ros::Duration(1.0);
  return ac.sendGoalAndWait(goal) == actionlib::SimpleClientGoalState::SUCCEEDED;
}
