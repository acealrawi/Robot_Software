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

    '''gripper_tcp_server Publisher'''
    pub = rospy.Publisher('gripperToAubo', String, queue_size=10)

    rospy.init_node('gripper_tcp_server', anonymous=True)

    rate = rospy.Rate(10) # 10hz

    client_socket, address = server.accept()
     
    print( 'Accepted connection from {}:{}'.format(address[0], address[1]))

    while not rospy.is_shutdown():
        handle_client_connection(client_socket)
        rate.sleep()


def handle_client_connection(client_socket, pub):
     request = client_socket.recv(1024).decode()
     pub.publisher(request)

if __name__ == '__main__':
    try:
        gripper_data_publisher()
    except rospy.ROSInterruptException:
        pass