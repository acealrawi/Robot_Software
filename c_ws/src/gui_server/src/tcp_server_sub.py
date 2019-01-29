#!/usr/bin/env python
'''tcp_server ROS Node'''
import rospy
from std_msgs.msg import String
import socket
import threading


def client_data_publisher():

    pub = rospy.Publisher("guiToAubo", String, queue_size=10)

    rospy.init_node('tcp_server', anonymous=True)

    # rate = rospy.Rate(10) # 10hz

    pub.publish("motion 0.3,0,0.2 0.4,0,0.3")


def handle_client_connection(client_socket, pub):
    request = client_socket.recv(1024).decode("utf-8")
    pub.publish(request)
    
if __name__ == '__main__':
    try:
        client_data_publisher()
    except rospy.ROSInterruptException:
        pass