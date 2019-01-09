#include <ros/ros.h>
#include <moving_core/PoseMessage.h>
#include <tf/tf.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <actionlib/client/simple_action_client.h>
// #include <control_msgs/FollowJointTrajectoryAction.h>


using namespace moving_core;
using namespace std;
using namespace ros;
using namespace geometry_msgs;
using namespace moveit::planning_interface;



void PoseCallback(const PoseMessageConstPtr& msg){
    ROS_INFO("PoseCallBack Start");

    // actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> ac_("joint_trajectory_action", true);

    ROS_INFO_STREAM("part localized: " << msg->pose);

    Pose move_target = msg->pose;
    MoveGroupInterface move_group("manipulator");

    // // Plan for robot to move to part
    move_group.stop();
    move_group.setPoseReferenceFrame("world");
    move_group.setPoseTarget(move_target);
    move_group.asyncMove();
    

    ROS_INFO("Done");
  }

int main(int argc, char **argv)
{
  init(argc, argv, "moving_node");
  NodeHandle nh;

  ROS_INFO("ScanNPlan node has been initialized");

  string base_frame;


  ros::Subscriber sub = nh.subscribe("PoseMessage", 1000, PoseCallback);
  spin();


}
