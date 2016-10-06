import serial #imports pyserial
import string #import string toolbox
import math   #imports python math
import time   #imports python time
import pickle #imports pickle
import matplotlib.pyplot as plt #imports matplotlib
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

data = [("45;53.13;7.071\r\n")]


print data


for line in data:  #iterate thru data except 'end' string
    line=line.replace("\r\n","")  #remove string escapes
    line = line.split(';')   #split by index
    print line[2]
    sensorrange = polydegrees[0]*float(line[2])**2 +polydegrees[1]*float(line[2]) + polydegrees[2]
    print sensorrange
    x = float(line[2])*math.cos(math.radians(float(line[1])))*math.sin(math.radians(float(line[0])))  #Convert to cartesian coords
    y = float(line[2])*math.sin(math.radians(float(line[0])))*math.sin(math.radians(float(line[1])))
    z = float(line[2])*math.cos(math.radians(float(line[0])))
    xdata.append(x)  #write data
    ydata.append(y)
    zdata.append(z)
print xdata
print ydata
print zdata
ax.scatter(xdata, ydata,zdata, zdir='z') #plot
plt.show() #show plot
            
