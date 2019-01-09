// #include <ros/ros.h>
// #include <fake_ar_publisher/ARMarker.h>
// #include <visualization_msgs/Marker.h>
// #include <coordination_publisher/coordination.h>

// using namespace coordination_publisher;

// ros::Publisher ar_pub;
// ros::Publisher visual_pub;

// static std::string& camera_frame_name()
// {
//   static std::string camera_frame;
//   return camera_frame;
// } 

// // Singleton Instance of Object Position
// static geometry_msgs::Pose& pose()
// {
//   static geometry_msgs::Pose pose;
//   return pose;
// }

// // Given a marker w/ pose data, publish an RViz visualization
// // You'll need to add a "Marker" visualizer in RVIZ AND define
// // the "camera_frame" TF frame somewhere to see it.
// static void pubVisualMarker(const fake_ar_publisher::ARMarker& m)
// {
//   const double width = 0.08;
//   const double thickness = 0.005;
  
//   visualization_msgs::Marker marker;
//   marker.header.frame_id = m.header.frame_id;
//   marker.header.stamp = ros::Time::now();
//   marker.ns = "ar_marker_visual";
//   marker.id = 0;
//   marker.type = visualization_msgs::Marker::CUBE;
//   marker.action = visualization_msgs::Marker::ADD;
//   marker.pose = m.pose.pose;
//   marker.pose.position.z -= thickness / 2.0;
//   marker.scale.x = width;
//   marker.scale.y = width;
//   marker.scale.z = thickness;
//   marker.color.a = 1.0;
//   marker.color.b = 1.0;
  
//   visual_pub.publish(marker);
// }

// void pubCallback(const ros::TimerEvent&)
// {
//   geometry_msgs::Pose p = pose();
//   fake_ar_publisher::ARMarker m;
//   m.header.frame_id = camera_frame_name();
//   m.header.stamp = ros::Time::now();
//   m.pose.pose = p;

//   ar_pub.publish(m);
  
//   pubVisualMarker(m); // visualize the marker
// }

// void chatterCallback(const coordinationConstPtr& msg)
// {
//   // init pose

//   pose().orientation.w = 1.0; // facing straight up
//   pose().position.x = msg->aX;
//   pose().position.y = msg->aY;
//   pose().position.z = msg->aZ;
//   camera_frame_name() = "camera_frame";

//   ROS_INFO("X_Coordinate: [%f]", pose().position.x);
// 	ROS_INFO("Y_Coordinate: [%f]", pose().position.y);
// 	ROS_INFO("Z_Coordinate: [%f]", pose().position.z);
//   geometry_msgs::Pose p = pose();
//   fake_ar_publisher::ARMarker m;
//   m.header.frame_id = camera_frame_name();
//   m.header.stamp = ros::Time::now();
//   m.pose.pose = p;

//   ar_pub.publish(m);
  
//   pubVisualMarker(m); // visualize the marker
// }

// int main(int argc, char **argv)
// {
//   // Set up ROS.
//   ros::init(argc, argv, "fake_ar_publisher");
//   ros::NodeHandle nh, pnh ("~");
//   ar_pub = nh.advertise<fake_ar_publisher::ARMarker>("ar_pose_marker", 1);
//   visual_pub = nh.advertise<visualization_msgs::Marker>("ar_pose_visual", 1);
//   ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
  
  

//   ROS_INFO("Starting simulated ARMarker publisher");  
//   // ros::Timer t = nh.createTimer(ros::Duration(0.1), pubCallback, false, true);
//   ros::spin();
//   // return 0;
// }

#include <ros/ros.h>
#include <ar_publisher/ARMarker.h>
#include <visualization_msgs/Marker.h>
#include <coordination_publisher/coordination.h>

ros::Publisher ar_pub;
ros::Publisher visual_pub;
using namespace coordination_publisher;

static std::string& camera_frame_name()
{
  static std::string camera_frame;
  return camera_frame;
} 

// Singleton Instance of Object Position
static geometry_msgs::Pose& pose()
{
  static geometry_msgs::Pose pose;
  return pose;
}

// Given a marker w/ pose data, publish an RViz visualization
// You'll need to add a "Marker" visualizer in RVIZ AND define
// the "camera_frame" TF frame somewhere to see it.
static void pubVisualMarker(const ar_publisher::ARMarker& m)
{
  const double width = 0.08;
  const double thickness = 0.005;
  
  visualization_msgs::Marker marker;
  marker.header.frame_id = m.header.frame_id;
  marker.header.stamp = ros::Time::now();
  marker.ns = "ar_marker_visual";
  marker.id = 0;
  marker.type = visualization_msgs::Marker::CUBE;
  marker.action = visualization_msgs::Marker::ADD;
  marker.pose = m.pose.pose;
  marker.pose.position.z -= thickness / 2.0;
  marker.scale.x = width;
  marker.scale.y = width;
  marker.scale.z = thickness;
  marker.color.a = 1.0;
  marker.color.b = 1.0;
  
  visual_pub.publish(marker);
}

void pubCallback(const coordinationConstPtr& msg)
{
  pose().orientation.w = 1.0; // facing straight up
  pose().position.x = msg->aX;
  pose().position.y = msg->aY;
  pose().position.z = msg->aZ;
  camera_frame_name() = "camera_frame";

  ROS_INFO("X_Coordinate: [%f]", pose().position.x);
	ROS_INFO("Y_Coordinate: [%f]", pose().position.y);
	ROS_INFO("Z_Coordinate: [%f]", pose().position.z);

  geometry_msgs::Pose p = pose();
  ar_publisher::ARMarker m;
  m.header.frame_id = camera_frame_name();
  m.header.stamp = ros::Time::now();
  m.pose.pose = p;

  ar_pub.publish(m);
  
  // pubVisualMarker(m); // visualize the marker
}

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "ar_publisher");
  ros::NodeHandle nh, pnh ("~");
  
  ar_pub = nh.advertise<ar_publisher::ARMarker>("ar_pose_marker", 1);
  ros::Subscriber sub = nh.subscribe("chatter", 1000, pubCallback);


  ROS_INFO("Starting simulated ARMarker publisher");  
  // ros::Timer t = nh.createTimer(ros::Duration(0.1), pubCallback, false, true);
  ros::spin();
}