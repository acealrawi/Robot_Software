#!/usr/bin/env python
'''gripper_tcp_server ROS Node'''
# license removed for brevity
import rospy
from std_msgs.msg import String
import socket
import threading

bind_ip = '192.168.10.101'
bind_port = 13001

def gripper_data_publisher():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((bind_ip, bind_port))
    server.listen(1)
    
    print('Listening on {}:{}'.format(bind_ip, bind_port))
    client_socket, address = server.accept()
    '''gripper_tcp_server Publisher'''
    rospy.init_node('gripper_tcp_server', anonymous=True)
    pub = rospy.Publisher('gripperToAubo', String, queue_size=10)
    rospy.Subscriber("robotToGripper", String, robotToGripper_callback, (client_socket,))
    rate = rospy.Rate(10) # 10hz
    
    # client_socket, address = server.accept()
     
    print( 'Accepted connection from {}:{}'.format(address[0], address[1]))

    while not rospy.is_shutdown():
        handle_client_connection(client_socket,pub)
        rate.sleep()


def robotToGripper_callback(data, arg):
    client = arg[0]
    client.send(data.data)
    print "from robot"
    print data.data
    print "****************************************************"
def handle_client_connection(client_socket, pub):
     request = client_socket.recv(1024).decode()
     print "from gripper"
     print request
     print "****************************************************"
     pub.publish(request)

if __name__ == '__main__':
    try:
        gripper_data_publisher()
    except rospy.ROSInterruptException:
        pass