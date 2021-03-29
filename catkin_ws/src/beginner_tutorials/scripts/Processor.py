#!/usr/bin/env python

from cv_bridge import CvBridge
import rospy
import cv2
import numpy as np
import message_filters
from sensor_msgs.msg import Image
from beginner_tutorials.msg import IntwithHeader

cv_bridge = CvBridge()

def callback(img_msg):
    img = cv_bridge.imgmsg_to_cv2(img_msg)
    
    # image processing and resizing 
    pro_img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    pro_img=cv2.resize(pro_img,(28,28))
    
    pub = rospy.Publisher('Processed_Image', Image, queue_size=1)
    pub.publish(cv_bridge.cv2_to_imgmsg(pro_img))
    print ("processor published")
    

def processor():
    rospy.init_node('processor', anonymous=True)
    rospy.Subscriber("Image",Image,callback)
    rospy.spin()

if __name__ == '__main__':
    processor()
