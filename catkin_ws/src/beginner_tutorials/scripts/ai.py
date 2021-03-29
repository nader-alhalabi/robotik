#!/usr/bin/env python

from beginner_tutorials.srv import AIService , AIServiceResponse
import rospy
import torch
import torchvision
import cv2 
import os
import numpy as np
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

cv_bridge=CvBridge()
current_folder= os.path.dirname(os.path.abspath(__file__))
model=torch.load(current_folder+"/my_mnist_model.pt")
transform=torchvision.transforms.Compose([torchvision.transforms.ToTensor()])

def handle_image(req):
    img=cv_bridge.imgmsg_to_cv2(req.image)
    pic=transform(img)
    pred_number=model(pic.view(1,784))
    pred_number=np.exp(pred_number.detach().numpy())
    r=0.0
    i=0
    
    for c,v in enumerate(pred_number[0]):
        if(v>r):
            r=v
            i=c 
    return AIServiceResponse(i)

def add_two_ints_server():
    rospy.init_node('ai')
    s = rospy.Service('ai_image_processing', AIService, handle_image)
    print ("Ready to check image.")
    rospy.spin()

if __name__ == "__main__":
    add_two_ints_server()
