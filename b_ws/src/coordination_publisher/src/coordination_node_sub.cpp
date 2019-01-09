#include "ros/ros.h"
#include "std_msgs/String.h"
#include <coordination_publisher/coordination.h>

using namespace coordination_publisher;
using namespace std;


void chatterCallback(const coordinationConstPtr& msg)
{
	ROS_INFO("X_Coordinate: [%f]", msg->aX);
	ROS_INFO("Y_Coordinate: [%f]", msg->aY);
	ROS_INFO("Z_Coordinate: [%f]", msg->aZ);
}

int main(int argc, char *argv[])
{
	
	ros::init(argc, argv, "coordination_node_sub");


	ros::NodeHandle nodeHanlde;


	ros::Subscriber sub = nodeHanlde.subscribe("chatter", 1000, chatterCallback);


	ros::spin();

	return 0;
}