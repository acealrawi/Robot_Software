#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf/LinearMath/Quaternion.h>

// Define the planning group name
static const std::string PLANNING_GROUP = "manipulator";

void Home(){
  // Create a planning group interface object and set up a planning group
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
  std::vector<double> home_position;

  home_position.push_back(-0.001255);
  home_position.push_back(-0.148822);
  home_position.push_back(-1.406503);
  home_position.push_back(0.311441);
  home_position.push_back(-1.571295);
  home_position.push_back(-0.002450);
  // home_position.push_back(-0.001255);//foreArm_joint
  // home_position.push_back(-0.148822);//shoulder_joint
  // home_position.push_back(-1.406503);//upperArm_joint
  // home_position.push_back(0.091441);//wrist1_joint
  // home_position.push_back(1.571295);//wrist2_joint
  // home_position.push_back(0.002450);//wrist3_joint
  move_group.setJointValueTarget(home_position);
  move_group.move();
}

void posA(){
  moveit::planning_interface::MoveGroupInterface move_group("manipulator");
  tf::Quaternion q;
  q.setRPY(3.14,0,-1.57);       //radian
  

  geometry_msgs::Pose target_pose1;
  //   target_pose1.position.x = 0.5;
  //   target_pose1.position.y = 0;
  //   target_pose1.position.z = 0.2;
  target_pose1.orientation.x = q.x();
  target_pose1.orientation.y = q.y();
  target_pose1.orientation.z = q.z();
  target_pose1.orientation.w = q.w();

  move_group.setPoseTarget(target_pose1);

  // Call the planner for planning calculations Note: This is just planning
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

  // Perform planning actions
  move_group.execute(my_plan);
}

void posB(){
  moveit::planning_interface::MoveGroupInterface move_group("manipulator");
  
  std::vector<double> group_variable_values;
  move_group.getCurrentState()->copyJointGroupPositions(move_group.getCurrentState()->getRobotModel()->getJointModelGroup(move_group.getName()), group_variable_values);


  group_variable_values[0] = -1.0;
  move_group.setJointValueTarget(group_variable_values);


  // Call the planner for planning calculations Note: This is just planning
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

  // Perform planning actions
  move_group.execute(my_plan);
}

// void posC(){

//   moveit::planning_interface::MoveGroupInterface move_group("manipulator");
//   tf::Quaternion q;
//   q.setRPY(3.14,0,-1.57);

  
//   moveit_msgs::OrientationConstraint ocm;
//   ocm.link_name = "wrist3_Link";
//   ocm.header.frame_id = "base_link";
  
//   ocm.orientation.w = q.w();
//   ocm.orientation.x = q.x();
//   ocm.orientation.y = q.y();
//   ocm.orientation.z = q.z();
//   ocm.absolute_x_axis_tolerance = 0.2;   
//   ocm.absolute_y_axis_tolerance = 0.2;
//   ocm.absolute_z_axis_tolerance = 0.2;
//   ocm.weight = 1.0;

//   moveit_msgs::Constraints test_constraints;
//   test_constraints.orientation_constraints.push_back(ocm);
//   move_group.setPathConstraints(test_constraints);


//   robot_state::RobotState start_state(*move_group.getCurrentState());
//   geometry_msgs::Pose     start_pose2;
//   start_pose2.position.x = -0.4;
//   start_pose2.position.y = 0.05;
//   start_pose2.position.z = 0.54;
//   start_pose2.orientation.x = q.x();
//   start_pose2.orientation.y = q.y();
//   start_pose2.orientation.z = q.z();
//   start_pose2.orientation.w = q.w();


//   move_group.setPoseTarget(start_pose2);
//   move_group.move();

  
//   start_state.setFromIK(joint_model_group, start_pose2);
//   move_group.setStartState(start_state);

  
//   geometry_msgs::Pose target_pose3_1;
//   target_pose3_1.position.x = -0.4;
//   target_pose3_1.position.y = -0.19;
//   target_pose3_1.position.z = 0.41;
//   target_pose3_1.orientation.x = q.x();
//   target_pose3_1.orientation.y = q.y();
//   target_pose3_1.orientation.z = q.z();
//   target_pose3_1.orientation.w = q.w();
//   move_group.setPoseTarget(target_pose3_1);

  
//   move_group.setPlanningTime(20.0);

//   success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
//   ROS_INFO_NAMED("tutorial", "Visualizing plan 3 (constraints) %s", success ? "success" : "FAILED");




//   move_group.execute(my_plan);

//   move_group.setPoseTarget(start_pose2);
//   move_group.move();

//   move_group.clearPathConstraints();
// }

void posD(){
	moveit::planning_interface::MoveGroupInterface move_group("manipulator");
  tf::Quaternion q;
  q.setRPY(3.14,0,-1.57);
	geometry_msgs::Pose start_pose2;
  start_pose2.position.x = -0.4;
  start_pose2.position.y = 0.0;
  start_pose2.position.z = 0.4;
  start_pose2.orientation.x = q.x();
  start_pose2.orientation.y = q.y();
  start_pose2.orientation.z = q.z();
  start_pose2.orientation.w = q.w();


  std::vector<geometry_msgs::Pose> waypoints;
  waypoints.push_back(start_pose2);//init

  geometry_msgs::Pose target_pose3 = start_pose2;

  target_pose3.position.z -= 0.2;
  waypoints.push_back(target_pose3); //down

  target_pose3.position.z += 0.3;
  waypoints.push_back(target_pose3); //up

  target_pose3.position.x -= 0.3;
  waypoints.push_back(target_pose3);  // left

   target_pose3.position.z -= 0.2;
  waypoints.push_back(target_pose3);  // down


  target_pose3.position.z += 0.3;
  waypoints.push_back(target_pose3); //up
  // target_pose3.position.z += 0.2;
  // target_pose3.position.y += 0.2;
  // target_pose3.position.x -= 0.2;
  // waypoints.push_back(target_pose3);  // up and left


  move_group.setMaxVelocityScalingFactor(0.1);

  moveit_msgs::RobotTrajectory trajectory;
  const double jump_threshold = 0.0;
  const double eef_step = 0.01;
  double fraction = move_group.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);

	// Call the planner for planning calculations Note: This is just planning
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
	my_plan.trajectory_ = trajectory;
	move_group.execute(my_plan);
  // bool success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

  // // Perform planning actions
  // move_group.execute(my_plan);
}

void Box(){

	  // Create a planning group interface object and set up a planning group
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);


  // Create a planning scene interface object
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;


	 // Create an object of the visualization class
  namespace rvt = rviz_visual_tools;
  moveit_visual_tools::MoveItVisualTools visual_tools("base_link");
  visual_tools.deleteAllMarkers();


  // Load remote control tool
  visual_tools.loadRemoteControl();


  // Create text
  Eigen::Affine3d text_pose = Eigen::Affine3d::Identity();
  text_pose.translation().z() = 1.2;
  visual_tools.publishText(text_pose, "AUBO Demo", rvt::RED, rvt::XLARGE);
  // Text visualization takes effect
  visual_tools.trigger();
	  // **************************************************************************************************   Fifth example: adding obstacles
	moveit::planning_interface::MoveGroupInterface::Plan my_plan;
	bool success;
  // Set the target pose , RPY mode (rotation around the reference axis X, Y, Z)
  tf::Quaternion q;
  q.setRPY(3.14,0,-1.57);       //radian
  // Define a collision object
  moveit_msgs::CollisionObject collision_object;
  collision_object.header.frame_id = move_group.getPlanningFrame();


  // Set the ID of the object
  collision_object.id = "box1";


  // ********************************Defining a box (obstacle) added to the world
  shape_msgs::SolidPrimitive primitive;
  primitive.type = primitive.BOX;
  primitive.dimensions.resize(3);
  primitive.dimensions[0] = 0.4;
  primitive.dimensions[1] = 0.05;
  primitive.dimensions[2] = 0.4;

  // 设置盒子(障碍物)的位置和姿态
  // Set the box (obstacle) pose
  geometry_msgs::Pose box_pose;
  box_pose.orientation.w = 1.0;
  box_pose.position.x = -0.3;
  box_pose.position.y = 0.2;
  box_pose.position.z = 0.54;


  collision_object.primitives.push_back(primitive);
  collision_object.primitive_poses.push_back(box_pose);
  collision_object.operation = collision_object.ADD;


  // *********************************Defining a box (desktop) added in the world
  moveit_msgs::CollisionObject collision_object2;
  collision_object2.header.frame_id = move_group.getPlanningFrame();

  // Set the ID of the object
  collision_object2.id = "box2";


  // Set length, width and height
  shape_msgs::SolidPrimitive primitive2;
  primitive2.type = primitive.BOX;
  primitive2.dimensions.resize(3);
  primitive2.dimensions[0] = 1.7;
  primitive2.dimensions[1] = 1.7;
  primitive2.dimensions[2] = 0.05;


  // Set the box (Desktop) pose
  geometry_msgs::Pose box_pose2;
  box_pose2.orientation.w = 1.0;
  box_pose2.position.x = 0.0;
  box_pose2.position.y = 0.0;
  box_pose2.position.z = 0.0;

  collision_object2.primitives.push_back(primitive2);
  collision_object2.primitive_poses.push_back(box_pose2);
  collision_object2.operation = collision_object2.ADD;


  std::vector<moveit_msgs::CollisionObject> collision_objects;
  collision_objects.push_back(collision_object);
  collision_objects.push_back(collision_object2);

  planning_scene_interface.addCollisionObjects(collision_objects);


  // Show text in RViz of status
  visual_tools.deleteAllMarkers();
  visual_tools.publishText(text_pose, "AUBO Add object Example5", rvt::RED, rvt::XLARGE);
  visual_tools.trigger();

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "move");
  ros::NodeHandle node_handle;

  // Start a thread
  ros::AsyncSpinner spinner(1);
  spinner.start();

//     // Create a planning scene interface object
//   moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

//   // Create a robot model information object
//   const robot_state::JointModelGroup* joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

  //***************************************************************************************************
  //Home Position
   Home();
  //  posC();
  //  posD();

//    Home();
    
   ros::shutdown();
   return 0;
  target_pose3.position.z += 0.2;
  waypoints.push_back(target_pose3); //up
}

