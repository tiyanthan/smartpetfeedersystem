import matplotlib.pyplot as plt
import cv2
import urllib
import urllib.request
import numpy as np
import sys
import os

config_file = 'Python/ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
frozen_model = 'Python/frozen_inference_graph.pb'

model = cv2.dnn_DetectionModel(frozen_model,config_file)


classLabels = [] 
file_name = 'labels.txt'
with open(file_name,'rt') as fpt:
    classLabels = fpt.read().rstrip('\n').split('\n')

model.setInputSize(320,320)
model.setInputScale(1.0/127.5)
model.setInputMean((127.5,127.5,127.5))
model.setInputSwapRB(True)

if(sys.argv[2]=='post'):
    req = urllib.request.urlopen(sys.argv[1])
else:
    req=open('images/'+sys.argv[1],'rb')
arr = np.asarray(bytearray(req.read()), dtype=np.uint8)
img = cv2.imdecode(arr, -1) 
req.close()
# os.remove('images/'+sys.argv[1]) 

ClassIndex, confidence, bbox = model.detect(img,confThreshold=0.6)
if (len(ClassIndex)!=0):
    for ClassInd in ClassIndex.flatten():
        if(ClassInd<80 and ClassInd>1):{
            print(ClassInd-1)
        }
        else:{
            print(ClassInd)
        }
else: print('()')
sys.stdout.flush()
