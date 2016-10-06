import serial 
import string 
import math   
import time   
import pickle 
import matplotlib.pyplot as plt 
import numpy
from mpl_toolkits.mplot3d import Axes3D #imports 3d axis 
fig = plt.figure() #makes matplotlib figure
ax = fig.add_subplot(111, projection='3d') #adds 3d subplot
data = [] #list for data
xdata = [] #list for x points
ydata = [] #list for y points
zdata = [] #list for z points
trigger = True #variable to keep track of if the scanner is done
calibrationvoltage = [476,378,315,289,275,264] 
calibrationrange = [20,30,40,50,60,70]
polydegrees = numpy.polyfit(calibrationvoltage,calibrationrange,2)
print polydegrees

data = pickle.load( open('save.p','rb')) #load test data from file
print data
for line in data:  #iterate thru data except 'end' string
    line=line.replace("\r\n","")  #remove string escapes
    line = line.split(';')   #split by index
    print line[2] #program is verbose for diagnostics
    if float(line[2]) <= 264 or float(line[2]) >= 476 or float(line[0]) != 6: #checks for points outside of calibration curve
            print "Bad point"  #lets the user know if it throws out point
    else:
        sensorrange = polydegrees[0]*float(line[2])**2 +polydegrees[1]*float(line[2]) + polydegrees[2]
        print sensorrange
        x = float(sensorrange)*math.cos(math.radians(float(line[1])))*math.sin(math.radians(float(line[0])*3))  #Convert to cartesian coords
        y = float(sensorrange)*math.sin(math.radians(float(line[0])*3))*math.sin(math.radians(float(line[1])))
        z = float(sensorrange)*math.cos(math.radians(float(line[0])*3))
        xdata.append(x)  #write data
        ydata.append(y)
        zdata.append(z)
ax.scatter(ydata, xdata,zdata, zdir='z') #plot
ax.set_xlim3d(0,100)
ax.set_zlim3d(0,100)
ax.set_ylim3d(0,100)


plt.show() #show plot
            
