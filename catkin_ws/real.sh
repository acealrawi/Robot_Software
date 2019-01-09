source devel/setup.bash
roslaunch aubo_i5_moveit_config moveit_planning_execution.launch  sim:=false robot_ip:=192.168.10.102
# roslaunch ur_bringup ur5_bringup.launch robot_ip:=192.168.10.102
# roslaunch plan_and_run aubo_setup.launch sim:=false robot_ip:=192.168.10.102 