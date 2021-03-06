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
import threading
import tf
import time



class MoveGroupPythonInteface(object):
    def __init__(self):
        super(MoveGroupPythonInteface, self).__init__()

        moveit_commander.roscpp_initialize(sys.argv)
        rospy.init_node('move', anonymous=True)

        rospy.Subscriber("guiToAubo", String, self.handle_gui_callback)
        rospy.Subscriber("gripperToAubo", String, self.handle_gripper_callback)

        # Global variables    
        self.gripper_server_publisher = rospy.Publisher('robotToGripper', String, queue_size=10)
        self.robot = moveit_commander.RobotCommander()
        self.scene = moveit_commander.PlanningSceneInterface()
        self.group = moveit_commander.MoveGroupCommander("manipulator")
        self.display_trajectory_publisher = rospy.Publisher('/move_group/display_planned_path', moveit_msgs.msg.DisplayTrajectory, queue_size=20)
        self.planning_frame = self.group.get_planning_frame()
        self.eef_link = self.group.get_end_effector_link()
        self.group_names = self.robot.get_group_names()
        self.valveState = 0
        self.flipState = 0
        self.vacuumState = 0
        self.flipValue = 0

        rospy.spin()
        

#*******************************MOVEMENT PLANNING**********************
    def place(self, end):
        waypoints = []
        scale = 1
        
        end_x, end_y, end_z = self.coordination_decoder(end)
        
        wpose = self.group.get_current_pose().pose
        waypoints.append(copy.deepcopy(wpose))
        
        wpose.position.z += scale * 0.3
        waypoints.append(copy.deepcopy(wpose))

        wpose.position.x -= scale * end_x
        waypoints.append(copy.deepcopy(wpose))
        
        wpose.position.z -= scale * end_z
        waypoints.append(copy.deepcopy(wpose))

        (plan, fraction) = self.group.compute_cartesian_path(waypoints, 0.01, 0.0)

        self.execute_plan(plan)
        self.publish_valve_value(0)

        while self.valveState == 1:
            print "wating for the valve to turn off"
            # self.valveState = 0
            time.sleep(1)

    def pick(self, start):
        waypoints = []
        start_x, start_y, start_z = self.coordination_decoder(start)
        
        wpose = geometry_msgs.msg.Pose()
        q = tf.transformations.quaternion_from_euler(3.14,0,-1.57)
        
        wpose.position.x = -start_x
        wpose.position.y = start_y
        wpose.position.z = start_z

        wpose.orientation.x = q[0]
        wpose.orientation.y = q[1]
        wpose.orientation.z = q[2]
        wpose.orientation.w = q[3]
        waypoints.append(copy.deepcopy(wpose))

        (plan, fraction) = self.group.compute_cartesian_path(waypoints, 0.01, 0.0)

        self.execute_plan(plan)

        self.publish_valve_value(1)
        while self.valveState == 0:
            print "wating for the valve to turn on"
            # self.valveState = 1
            time.sleep(1)

    def go_to_pose_goal(self, start, end):
        # Copy class variables to local variables to make the web tutorials more clear.
        # In practice, you should use the class variables directly unless you have a good
        # reason not to.
        group = self.group
        start_x, start_y, start_z = self.coordination_decoder(start)
        end_x, end_y, end_z = self.coordination_decoder(end)
        
        self.home()
        pose_goal = geometry_msgs.msg.Pose()
        q = tf.transformations.quaternion_from_euler(3.14,0,-1.57)
        
        pose_goal.position.x = -start_x
        pose_goal.position.y = start_y
        pose_goal.position.z = start_z

        pose_goal.orientation.x = q[0]
        pose_goal.orientation.y = q[1]
        pose_goal.orientation.z = q[2]
        pose_goal.orientation.w = q[3]
        group.set_pose_target(pose_goal)
        print "first"
        pose_goal.position.x = -start_x
        pose_goal.position.y = start_y
        pose_goal.position.z = 0.3
        
        pose_goal.orientation.x = q[0]
        pose_goal.orientation.y = q[1]
        pose_goal.orientation.z = q[2]
        pose_goal.orientation.w = q[3]
        group.set_pose_target(pose_goal)
        print "second"
        pose_goal.position.x = -end_x
        pose_goal.position.y = end_y
        pose_goal.position.z = end_z

        pose_goal.orientation.x = q[0]
        pose_goal.orientation.y = q[1]
        pose_goal.orientation.z = q[2]
        pose_goal.orientation.w = q[3]
        group.set_pose_target(pose_goal)
        print "third"
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

        # wpose = self.group.get_current_pose().pose
        start_x, start_y, start_z = self.coordination_decoder(start)
        end_x, end_y, end_z = self.coordination_decoder(end)
        
        wpose = geometry_msgs.msg.Pose()
        q = tf.transformations.quaternion_from_euler(3.14,0,-1.57)
        
        wpose.position.x = -start_x
        wpose.position.y = start_y
        wpose.position.z = start_z

        wpose.orientation.x = q[0]
        wpose.orientation.y = q[1]
        wpose.orientation.z = q[2]
        wpose.orientation.w = q[3]
        waypoints.append(copy.deepcopy(wpose))

        # wpose.position.z -= scale * start_z
        # waypoints.append(copy.deepcopy(wpose))

        self.publish_valve_value(1)
        while self.valveState == 0:
            print "wating for the valve to turn on"
            time.sleep(20)
        
        wpose.position.z += scale * 0.3
        waypoints.append(copy.deepcopy(wpose))


        wpose.position.x -= scale * 0.3
        waypoints.append(copy.deepcopy(wpose))
        
        wpose.position.z -= scale * 0.1
        waypoints.append(copy.deepcopy(wpose))

        
        self.publish_valve_value(0)

        while self.valveState == 1:
            print "wating for the valve to turn off"
            time.sleep(20)
        
        wpose.position.z += scale * 0.3  
        waypoints.append(copy.deepcopy(wpose))

        # We want the Cartesian path to be interpolated at a resolution of 1 cm
        # which is why we will specify 0.01 as the eef_step in Cartesian
        # translation.  We will disable the jump threshold by setting it to 0.0 disabling:
        (plan, fraction) = self.group.compute_cartesian_path(
                                        waypoints,   # waypoints to follow
                                        0.01,        # eef_step
                                        0.0)         # jump_threshold
        return plan, fraction

#*******************************MOVEMENT EXECUTION*********************
    def plan_and_execute(self, start, end, scale=1):
        print "home"
        self.home()
        print "plan"
        plan, fraction = self.plan_cartesian_path(start, end, scale)
        self.execute_plan(plan)

    def execute_plan(self, plan):
        print "executing"
        self.group.execute(plan, wait=True)
    def execute_pick_and_place(self, motion_message):
        self.home()
        start, end = self.motion_decoder(motion_message)
        self.pick(start)
        self.place(end)
        self.home()

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
        group.stop()

#*******************************PUBLISHERS*****************************
    def publish_valve_value(self, value):
        self.gripper_server_publisher.publish("valveValue:{0}".format(value))
    def publish_flip_value(self, value):
        self.gripper_server_publisher.publish("flipValue:{0}".format(value))

#*******************************UTILITIES******************************
    def motion_decoder(self, motion):
        message = motion.split(' ')
        start = message[1]
        end = message[2]
        return start, end

    def coordination_decoder(self, coordination):
        x,y,z = coordination.split(',')
        return float(x.strip()),float(y.strip()),float(z.strip())

    def reverse_digital_value(self, value):
        if value == 1:
            return 0
        else:
            return 1

    def key_value_pair_decoder(self, message):
        state = int(message.split(':')[1].strip())
        return state

    def display_trajectory(self, plan):
        robot = self.robot
        display_trajectory_publisher = self.display_trajectory_publisher
        display_trajectory = moveit_msgs.msg.DisplayTrajectory()
        display_trajectory.trajectory_start = robot.get_current_state()
        display_trajectory.trajectory.append(plan)
        # Publish
        display_trajectory_publisher.publish(display_trajectory);

    def print_information(self):
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

#*******************************COMMANDS*******************************
    def handle_motion_command(self, request):
        thread = threading.Thread(target=self.execute_pick_and_place, args=(request,))
        thread.start()

    def handle_flip_command(self):
        flipValue = self.reverse_digital_value(self.flipState):
        self.publish_flip_value(flipValue)

    def handle_valve_command(self):
        valveValue = self.reverse_digital_value(self.valveState):
        self.publish_valve_value(valveValue)

#*******************************MESSAGES*******************************
    def handle_valve_message(self, state):
        self.valveState = self.key_value_pair_decoder(state)

    def handle_flip_message(self, state):
        self.flipState = self.key_value_pair_decoder(state)

    def handle_vacuum_message(self, state):
        self.vacuumState = self.key_value_pair_decoder(state)

#*******************************CALLBACKS******************************
    def handle_gui_callback(self, data):
        request = data.data
        if request.startswith("motion"):
            self.handle_motion_command(request)
        # if request.startswith("stop"):
            
        if request.startswith("flip"):
            self.handle_flip_command()
            
        if request.startswith("home"):
            self.home()
            
        if request.startswith("valve"):
            self.handle_valve_command()

    def handle_gripper_callback(self, data):
        request = data.data
        if request.startswith("valveState"):
            self.handle_valve_message(request)

        if request.startswith("flipState"):
            self.handle_flip_message(request)

        if request.startswith("vacuumState"):
            self.handle_vacuum_message(request)


#*******************************TESTS**********************************
    def test_run(self):
        print "**********STARTING TEST RUN**********"
        self.home()
        motion_message = "motion 0.3,0,0.2 0.4,0,0.1"
        start, end = self.motion_decoder(motion_message)
        self.pick(start)
        self.place(end)
        self.home()
        print "**********TEST RUN END**********"

def main():
  try:
    mgpi = MoveGroupPythonInteface()
    # mgpi.test_run()
  except rospy.ROSInterruptException:
    return
  except KeyboardInterrupt:
    return

if __name__ == '__main__':
  main()


