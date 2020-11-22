#!/usr/bin/env python3


import rospy
import numpy as np
import cv2
import os
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

cv_b=CvBridge()

img_path= os.path.dirname(os.path.abspath(__file__))

def talker():

    pub = rospy.Publisher('Image', Image, queue_size=10)
    #pub2 = rospy.Publisher('Integer', String, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(1) # 10hz
    

    while not rospy.is_shutdown():
        #hello_str = "hello world %s" % rospy.get_time()
        #rospy.loginfo(hello_str)
        rand=np.random.randint(10)
        img=cv2.imread(img_path+ "/img.jpg")
        img_msg = cv_b.cv2_to_imgmsg(img)
        pub.publish(img_msg)
        #pub2.publish(rand)
        rospy.loginfo(img_msg)
        print("node published")
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
