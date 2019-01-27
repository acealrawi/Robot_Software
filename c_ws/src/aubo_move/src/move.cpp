#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <tf/LinearMath/Quaternion.h>
#include "ros/ros.h"
#include "std_msgs/String.h"


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
  move_group.setJointValueTarget(home_position);
  move_group.move();
}

void ExecuteMovement(){
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

int main(int argc, char** argv)
{
  ros::init(argc, argv, "move");
  ros::NodeHandle n;

  // Start a thread
  ros::AsyncSpinner spinner(1);
  spinner.start();
  // ros::Subscriber sub = n.subscribe("guiserver", 1000, GuiServerCallback);

    
   ros::shutdown();
   return 0;
}


// void GuiServerCallback(const std_msgs::String::ConstPtr& msg)
// {
// 	ROS_INFO("I heard: [%s]", msg->data.c_str());
//   string message = msg->data.c_str()
//   if(message.find("motion") == 0){

//   }
//   if(message.find("stop") == 0){

//   }
//   if(message.find("flip") == 0){

//   }
//   if(message.find("home") == 0){

//   }
//   if(message.find("suck") == 0){

//   }
// }

// void MotionDecoder(string message){
//   std::vector<string> motionList = Split(message, " ");

//   std::string start = motionList[0];
//   std::string end = motionList[1];
//   std::vector<string> startCoordination = Split(start, ",");
//   std::vector<string> endCoordination = Split(end, ",");

// }

// std::vector<string> Split(std::string stringToSplit, std::string delimiter){
//   std::vector<string> list;
//   size_t pos = 0;
//   std::string token;
//   while ((pos = stringToSplit.find(delimiter)) != std::string::npos) {
//       token = stringToSplit.substr(0, pos);
//       list.push_back(token);
//       stringToSplit.erase(0, pos + delimiter.length());
//   }
//   list.push_back(stringToSplit);
//   return list;
// }
// def motion_decoder(byteBuffer):
//     message = byteBuffer.split(' ')
//     start = message[1]
//     end = message[2]
//     return start, end

// def coordination_decoder(coordination):
//     x,y,z = coordination.split(',')
//     return x,y,z

// def handle_client_connection(client_socket):
//     request = client_socket.recv(1024).decode("utf-8")
//     if request.startswith('motion'):
//         start, end = motion_decoder(request)
//         x,y,z = coordination_decoder(start)
//         print(x)
//     if request.startswith('stop'):
//         print(request)
//     if request.startswith('flip'):
//         print(request)
//     if request.startswith('home'):
//         print(request)
//     if request.startswith('suck'):
//         print(request)
    
