#!/usr/bin/env python

import rospy
import numpy as np
from sensor_msgs.msg import Image
from beginner_tutorials.msg import IntwithHeader
import cv2
import os 
from cv_bridge import CvBridge

cv_bridge = CvBridge()
current_path = os.path.dirname(os.path.abspath(__file__))

def camera():
    rospy.init_node('camera', anonymous=True)
    pub = rospy.Publisher('Image', Image, queue_size=1)
    pub2 = rospy.Publisher('Int', IntwithHeader,queue_size=1)
    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
    	# picking a random img from current folder
        rand = np.random.randint(10)
        img = cv2.imread(current_path +"/"+str(rand)+ ".png")
        img_msg = cv_bridge.cv2_to_imgmsg(img)
	
        int_header = IntwithHeader()
        int_header.data = rand
        
        pub.publish(img_msg)
        pub2.publish(int_header)
        print ("Camera published")
        rate.sleep()

if __name__ == '__main__':
    try:
        camera()
    except rospy.ROSInterruptException:
        pass
