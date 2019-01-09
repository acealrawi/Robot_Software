#include "ros/ros.h"
#include "std_msgs/String.h"
#include <coordination_publisher/coordination.h>

#include <sstream>

using namespace std;
using namespace coordination_publisher;

int main(int argc, char *argv[])
{

	ros::init(argc, argv, "coordination_node_pub");

	ros::NodeHandle nodeHandle;

	ros::Publisher coordinationPublisher = nodeHandle.advertise<coordination>("chatter", 1000);

	ros::Rate loop_rate(10);

	int count = 0;
	while (ros::ok())
	{

		std_msgs::String message;


		
		float coordinationArray [3]; 

    	cout << "Give input\n";
		
		for (int i = 0; i < 3 ; i++)	{
			string input;
			getline(std::cin, input);
			coordinationArray[i] = stof(input);
		}
		
		coordination _coordination;
		_coordination.aX = coordinationArray[0];
		_coordination.aY = coordinationArray[1];
		_coordination.aZ = coordinationArray[2];


		ROS_INFO("[%f]-[%f]-[%f]", _coordination.aX,_coordination.aY,_coordination.aZ );

		coordinationPublisher.publish(_coordination);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}

	return 0;
}