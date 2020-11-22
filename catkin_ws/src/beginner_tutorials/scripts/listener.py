#!/usr/bin/env python3


import rospy
import cv2
import numpy as np
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

cv_bridge=CvBridge()

def callback(data):
    #rospy.loginfo(rospy.get_caller_id() + 'I heard %s', data.data)
    
    img = cv_bridge.imgmsg_to_cv2(data)
    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    #gray=cv2.resize(gray,(1,28*28))
    
    gray=cv2.resize(gray,(28,28))
    
    pub=rospy.Publisher('Processed_Image', Image, queue_size=1)
    pub.publish(cv_bridge.cv2_to_imgmsg(gray))
    print("processor published new")

def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber('Image', Image, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
