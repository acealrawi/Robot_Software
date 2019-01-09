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
  ros::init(argc, argv, "move_group_interface_tutorial");
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
  visual_tools.publishText(text_pose, "AUBO Demo", rvt::RED, rvt::XLARGE);
  // Text visualization takes effect
  visual_tools.trigger();


  // Get the coordinate system of the basic information
  ROS_INFO_NAMED("tutorial", "Planning frame: %s", move_group.getPlanningFrame().c_str());


  // Get the end of the basic information
  ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group.getEndEffectorLink().c_str());


  // Visual terminal prompt (blocking)
  visual_tools.prompt("Press 'next'1 in the RvizVisualToolsGui window to start the demo");
 


  visual_tools.prompt("Press 'next'5  ADD a OBject in the RvizVisualToolsGui window to continue the demo");








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

  visual_tools.prompt("Press 'next'6 in the RvizVisualToolsGui window to once the collision object appears in RViz");



  // **************************************************************************************************   Sixth example: obstacle avoidance movement


//   // Add a track to avoid obstacle movement
//   q.setRPY(1.77,-0.59,-1.79 );                       // radian

//   move_group.setStartState(*move_group.getCurrentState());
//   geometry_msgs::Pose another_pose;
//   another_pose.orientation.x = q.x();
//   another_pose.orientation.y = q.y();
//   another_pose.orientation.z = q.z();
//   another_pose.orientation.w = q.w();
//   another_pose.position.x = -0.37;
//   another_pose.position.y = 0.6;
//   another_pose.position.z = 0.4;
//   move_group.setPoseTarget(another_pose);

//   success = (move_group.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
//   ROS_INFO_NAMED("tutorial", "Visualizing plan 5 (pose goal move around cuboid) %s", success ? "" : "FAILED");


//   // Visualize the plan in RViz
//   visual_tools.deleteAllMarkers();
//   visual_tools.publishText(text_pose, "AUBO Obstacle Goal Exalmple6", rvt::RED, rvt::XLARGE);
//   visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
//   visual_tools.trigger();


//   // Perform planning actions
//   move_group.execute(my_plan);


//   visual_tools.prompt("next step 7 attach the collision object to the robot");



//   // **************************************************************************************************   Seventh example: Simulated collision

//   ROS_INFO_NAMED("tutorial", "Attach the object to the robot");
//   move_group.attachObject(collision_object.id);

//   visual_tools.publishText(text_pose, "AUBO Object attached to robot Example7", rvt::RED, rvt::XLARGE);
//   visual_tools.trigger();

//   visual_tools.prompt("Press 'next'8 in the RvizVisualToolsGui window to once the collision object attaches to the "
//                       "robot");



//   // **************************************************************************************************   Eighth example: Simulated no collision

//   ROS_INFO_NAMED("tutorial", "Detach the object from the robot");
//   move_group.detachObject(collision_object.id);

//   visual_tools.publishText(text_pose, "AUBO Object dettached from robot Example8", rvt::RED, rvt::XLARGE);
//   visual_tools.trigger();

//   visual_tools.prompt("Press 'next'9 in the RvizVisualToolsGui window to once the collision object detaches to the "
//                       "robot");




//   //**************************************************************************************************    Ninth example: removing obstacles


//   // Remove obstacles
//   ROS_INFO_NAMED("tutorial", "Remove the object from the world");
//   std::vector<std::string> object_ids;
//   object_ids.push_back(collision_object.id);
//   planning_scene_interface.removeCollisionObjects(object_ids);

//   visual_tools.deleteAllMarkers();
//   visual_tools.publishText(text_pose, "AUBO Object1 removed EXample9", rvt::RED, rvt::XLARGE);
//   visual_tools.trigger();



//    //**************************************************************************************************    Tenth example: random motion (screened, users need to be able to open it themselves. Tip: random motion is uncertain, users need to hold the emergency stop to pay attention to safety)



// //   visual_tools.deleteAllMarkers();
// //   visual_tools.publishText(text_pose, "AUBO Random Move Exalmple 10", rvt::RED, rvt::XLARGE);
// //   visual_tools.trigger();

// //   for(int i=0;i<30;i++)
// //   {

// //     move_group.setRandomTarget();

// //     move_group.move();

// //     ROS_INFO_NAMED("tutorial", "Random Moving %d:",i);

// //   }
// //   visual_tools.prompt("Press 'next'10 : Robot Random Moving");


//    // Remove the desktop
//    ROS_INFO_NAMED("tutorial", "Remove the desktop from the world");
//    object_ids.push_back(collision_object2.id);
//    planning_scene_interface.removeCollisionObjects(object_ids);
//    // Show text in RViz of status
//    visual_tools.deleteAllMarkers();
//    visual_tools.publishText(text_pose, " Finish ", rvt::RED, rvt::XLARGE);
//    visual_tools.trigger();


   // END_TUTORIAL
   ros::shutdown();
   return 0;
}
