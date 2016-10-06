import serial 
import string 
import math  
import time   
import pickle 
import matplotlib.pyplot as plt 
import numpy 
from mpl_toolkits.mplot3d import Axes3D #imports 3d axis 
data = [] #list for data
pandata = [] #list for pan points
tiltdata = [] #list for tilt points
rangedata = [] #list for range points
#calibration data set
calibrationvoltage = [476,378,315,289,275,264] 
calibrationrange = [20,30,40,50,60,70]
#calibration polynomial best fit
polydegrees = numpy.polyfit(calibrationvoltage,calibrationrange,2)
#load test data from file
data = pickle.load( open('save.p','rb')) 
for line in data:  #iterate thru data except 'end' string
    line=line.replace("\r\n","")  #remove string escapes
    line = line.split(';')   #split by index
    #convert from voltage to sensor range
    sensorrange = polydegrees[0]*float(line[2])**2 +polydegrees[1]*float(line[2]) + polydegrees[2]
    #convert from spherical to cartesian
    x = float(sensorrange)*math.cos(math.radians(180-float(line[1])))*math.sin(math.radians(180-float(line[0])))  
    y = float(sensorrange)*math.sin(math.radians(180-float(line[0])))*math.sin(math.radians(180-float(line[1])))
    z = float(sensorrange)*math.cos(math.radians(180-float(line[0])))
    pandata.append(line[0])  #write data
    tiltdata.append(line[1])   
    rangedata.append(sensorrange)
color = [str(item/255) for item in rangedata] #assign an arbitrary color to each range value
plt.scatter(pandata, tiltdata,c =color ) #plot
plt.show() #show plot
            
