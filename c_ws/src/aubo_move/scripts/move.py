#!/usr/bin/env python
import sys
import copy
import rospy
import moveit_commander
import moveit_msgs.msg
import geometry_msgs.msg
from math import pi
from std_msgs.msg import String
from moveit_commander.conversions import pose_to_list


class MoveGroupPythonInteface(object):
    def __init__(self):
        super(MoveGroupPythonInteface, self).__init__()

        moveit_commander.roscpp_initialize(sys.argv)
        rospy.init_node('move', anonymous=True)

        rospy.Subscriber("guiToAubo", String, handle_gui_callback)
        rospy.Subscriber("gripperToAubo", String, handle_gripper_callback)

        # Global variables    
        self.gripper_server_publisher = rospy.Publisher('gripperserver', String, queue_size=10)
        self.robot = moveit_commander.RobotCommander()
        self.scene = moveit_commander.PlanningSceneInterface()
        self.group = moveit_commander.MoveGroupCommander("manipulator")
        self.display_trajectory_publisher = rospy.Publisher('/move_group/display_planned_path', moveit_msgs.msg.DisplayTrajectory, queue_size=20)
        self.planning_frame = group.get_planning_frame()
        self.eef_link = group.get_end_effector_link()
        self.group_names = robot.get_group_names()
        self.valveState = 0
        self.flipState = 0
        self.vacuumState = 0

    def home(self):
        # Copy class variables to local variables to make the web tutorials more clear.
        # In practice, you should use the class variables directly unless you have a good
        # reason not to.
        group = self.group
        joint_goal = group.get_current_joint_values()
        joint_goal[0] = -0.001255
        joint_goal[1] = -0.148822
        joint_goal[2] = -1.406503
        joint_goal[3] = 0.311441
        joint_goal[4] = -1.571295
        joint_goal[5] = -0.002450

        # The go command can be called with joint values, poses, or without any
        # parameters if you have already set the pose or joint target for the group
        group.go(joint_goal, wait=True)

        # Calling ``stop()`` ensures that there is no residual movement
        group.stop()
        current_joints = self.group.get_current_joint_values()

    def go_to_pose_goal(self):
        # Copy class variables to local variables to make the web tutorials more clear.
        # In practice, you should use the class variables directly unless you have a good
        # reason not to.
        group = self.group
        pose_goal = geometry_msgs.msg.Pose()
        
        pose_goal.orientation.w = 1.0
        pose_goal.position.x = 0.4
        pose_goal.position.y = 0.1
        pose_goal.position.z = 0.4
        group.set_pose_target(pose_goal)

        ## Now, we call the planner to compute the plan and execute it.
        plan = group.go(wait=True)
        # Calling `stop()` ensures that there is no residual movement
        group.stop()
        # It is always good to clear your targets after planning with poses.
        # Note: there is no equivalent function for clear_joint_value_targets()
        group.clear_pose_targets()

        current_pose = self.group.get_current_pose().pose



    def plan_cartesian_path(self, start, end, scale=1):
        waypoints = []

        wpose = self.group.get_current_pose().pose
        start_x, start_y, start_z = self.coordination_decoder(start)
        end_x, end_y, end_z = self.coordination_decoder(end)

        wpose.position.z -= scale * start_z
        waypoints.append(copy.deepcopy(wpose))
        
        wpose.position.z += scale * 0.3
        waypoints.append(copy.deepcopy(wpose))

        wpose.position.x -= scale * 0.3
        waypoints.append(copy.deepcopy(wpose))
        
        wpose.position.z -= scale * end_z
        waypoints.append(copy.deepcopy(wpose))
        
        wpose.position.z += scale * 0.3  
        waypoints.append(copy.deepcopy(wpose))

        # We want the Cartesian path to be interpolated at a resolution of 1 cm
        # which is why we will specify 0.01 as the eef_step in Cartesian
        # translation.  We will disable the jump threshold by setting it to 0.0 disabling:
        (plan, fraction) = group.compute_cartesian_path(
                                        waypoints,   # waypoints to follow
                                        0.01,        # eef_step
                                        0.0)         # jump_threshold
        return plan, fraction
    def plan_and_execute(self, start, end, scale=1):
        plan, fraction = self.plan(self, start, end, scale)
        self.execute_plan(plan)
    
    def display_trajectory(self, plan):
        robot = self.robot
        display_trajectory_publisher = self.display_trajectory_publisher
        display_trajectory = moveit_msgs.msg.DisplayTrajectory()
        display_trajectory.trajectory_start = robot.get_current_state()
        display_trajectory.trajectory.append(plan)
        # Publish
        display_trajectory_publisher.publish(display_trajectory);

    def execute_plan(self, plan):
        self.group.execute(plan, wait=True)

    
    def motion_decoder(self, motion):
        message = motion.split(' ')
        start = message[1]
        end = message[2]
        return start, end

    def coordination_decoder(self, coordination):
        x,y,z = coordination.split(',')
        return float(x.strip()),float(y.strip()),float(z.strip())

    def handle_gui_callback(self, data):
        request = data.data
        if request.startswith("motion"):
            start, end = motion_decoder(request)
            self.plan_and_execute(start, end)
        if request.startswith("stop"):
            print(request)
        if request.startswith("flip"):
            self.gripper_server_publisher.publish(request)
            print(request)
        if request.startswith("home"):
            self.home()
            print(request)
        if request.startswith("suck"):
            self.gripper_server_publisher.publish(request)
            print(request)

    def handle_gripper_connection(self, data):
        request = data.data
        if request.startwith("valveState"):
            handle_valve_message()
        if request.startwith("flipState"):
            handle_flip_message()
        if request.startwith("vacuumState"):
            handle_vacuum_message()

    def gripper_message_decoder(self, message):
        state = int(message.split(':')[1].strip())
        return state

    def handle_valve_message(self, state, socket):
        self.valveState = gripper_message_decoder(message)
        socket.send()

    def handle_flip_message(self, state, socket):
        self.flipState = gripper_message_decoder(message)

    def handle_vacuum_message(self, state, socket):
        self.vacuumState = gripper_message_decoder(message)

    def print_information(self)
        # We can get the name of the reference frame for this robot:
        print "============ Reference frame: %s" % self.planning_frame

        # We can also print the name of the end-effector link for this group:
        print "============ End effector: %s" % self.eef_link

        # We can get a list of all the groups in the robot:
        print "============ Robot Groups:", self.robot.get_group_names()

        # Sometimes for debugging it is useful to print the entire state of the
        # robot:
        print "============ Printing robot state"
        print self.robot.get_current_state()
        print ""
    



def main():
  try:
    mgpi = MoveGroupPythonInteface()
    mgpi.home()
    plan, fraction = mgpi.plan_cartesian_path()
    mgpi.execute_plan(plan)
  except rospy.ROSInterruptException:
    return
  except KeyboardInterrupt:
    return

if __name__ == '__main__':
  main()


