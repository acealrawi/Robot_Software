#include <plan_and_run/demo_application.h>



namespace plan_and_run
{

void DemoApplication::moveHome()
{

  // creating move group interface for planning simple moves
  moveit::planning_interface::MoveGroupInterface move_group(config_.group_name);
  move_group.setPlannerId(PLANNER_ID);

  // setting home position as target
  if(!move_group.setNamedTarget(HOME_POSITION_NAME))
  {
    ROS_ERROR_STREAM("Failed to set home '"<<HOME_POSITION_NAME<<"' position");
    exit(-1);
  }

  moveit_msgs::MoveItErrorCodes result = move_group.move();
  if(result.val != result.SUCCESS)
  {
    ROS_ERROR_STREAM("Failed to move to "<<HOME_POSITION_NAME<<" position");
    exit(-1);
  }
  else
  {
    ROS_INFO_STREAM("Robot reached home position");
  }

  ROS_INFO_STREAM("Task '"<<__FUNCTION__<<"' completed");

}

}

