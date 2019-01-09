#include <plan_and_run/demo_application.h>

namespace plan_and_run
{

void DemoApplication::initRos()
{

  // creating publisher for trajectory visualization
  marker_publisher_  = nh_.advertise<visualization_msgs::MarkerArray>(VISUALIZE_TRAJECTORY_TOPIC,1,true);

  typedef actionlib::SimpleActionClient<moveit_msgs::ExecuteTrajectoryAction> client_type;
  moveit_run_path_client_ptr_ = std::make_shared<client_type>(EXECUTE_TRAJECTORY_ACTION,true);

  // Establishing connection to server
  if(moveit_run_path_client_ptr_->waitForServer(ros::Duration(SERVER_TIMEOUT)))
  {
    ROS_INFO_STREAM("Connected to '"<<EXECUTE_TRAJECTORY_ACTION<<"' action");
  }
  else
  {
    ROS_ERROR_STREAM("Failed to connect to '"<<EXECUTE_TRAJECTORY_ACTION<<"' action");
    exit(-1);
  }

  ROS_INFO_STREAM("Task '"<<__FUNCTION__<<"' completed");

}

}

