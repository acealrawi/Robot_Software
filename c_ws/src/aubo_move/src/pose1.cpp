#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf/LinearMath/Quaternion.h>



int main(int argc, char** argv)
{
  ros::init(argc, argv, "pose1");
  ros::NodeHandle node_handle;

  // Start a thread
  ros::AsyncSpinner spinner(1);
  spinner.start();


  // Define the planning group name
  static const std::string PLANNING_GROUP = "manipulator";


  // Create a planning group interface object and set up a planning group
  moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);


  // Create a planning scene interface object
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;


  // Create a robot model information object
  const robot_state::JointModelGroup* joint_model_group = move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);


  // Create an object of the visualization class
  namespace rvt = rviz_visual_tools;
  moveit_visual_tools::MoveItVisualTools visual_tools("base_link");
  visual_tools.deleteAllMarkers();


  // Load remote control tool
  visual_tools.loadRemoteControl();


  // Create text
  Eigen::Affine3d text_pose = Eigen::Affine3d::Identity();
  text_pose.translation().z() = 1.2;
  visual_tools.publishText(text_pose, "Home Poisition", rvt::RED, rvt::XLARGE);
  // Text visualization takes effect
  visual_tools.trigger();


  // Get the coordinate system of the basic information
  ROS_INFO_NAMED("home", "Planning frame: %s", move_group.getPlanningFrame().c_str());


  // Get the end of the basic information
  ROS_INFO_NAMED("home", "End effector link: %s", move_group.getEndEffectorLink().c_str());


  
  //***************************************************************************************************  Home Position

  std::vector<double> home_position;
  home_position.push_back(-0.001255);
  home_position.push_back(-0.148822);
  home_position.push_back(1.406503);
  home_position.push_back(0.311441);
  home_position.push_back(-1.571295);
  home_position.push_back(-0.002450);
  move_group.setJointValueTarget(home_position);
  move_group.move();
    
   ros::shutdown();
   return 0;
}