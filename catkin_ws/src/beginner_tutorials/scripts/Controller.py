#!/usr/bin/env python

import rospy 
import numpy as np
import message_filters
from sensor_msgs.msg import Image
from beginner_tutorials.msg import IntwithHeader
from beginner_tutorials.srv import AIService
import cv2 
from cv_bridge import CvBridge

cv_bridge=CvBridge()
values = []

def callback(info,img):
    p_img=cv_bridge.imgmsg_to_cv2(img)
    values.append((info.data,p_img))
    rospy.wait_for_service('ai_image_processing')
    try:
        ai_image_processing = rospy.ServiceProxy('ai_image_processing', AIService)
        req_img=cv_bridge.cv2_to_imgmsg(p_img)
        resp1 = ai_image_processing(req_img)
        res=resp1.result
        print ("actually requested: %s \nai response to Controller: %s"%(info.data,res))
    except rospy.ServiceException:
        print ("Service call failed: %s"%e)


def controller():
    rospy.init_node('Controller',anonymous=True)
    info_sub = message_filters.Subscriber('Int',IntwithHeader)
    pi_sub = message_filters.Subscriber('Processed_Image',Image)
    ts = message_filters.TimeSynchronizer([info_sub,pi_sub],1)
    ts.registerCallback(callback)
    rospy.spin()

if __name__ == '__main__':
    try:
        controller()
    except rospy.ROSInterruptException:
        pass
 
