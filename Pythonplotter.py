import serial 
import string 
import math  
import time   
import pickle 
import matplotlib.pyplot as plt 
import numpy 
from mpl_toolkits.mplot3d import Axes3D
#imports 3d axis 
fig = plt.figure() #makes matplotlib figure
ax = fig.add_subplot(111, projection='3d') #adds 3d subplot
data = [] #list for data
xdata = [] #list for x points
ydata = [] #list for y points
zdata = [] #list for z points
trigger = True #variable to keep track of if the scanner is done
#calibration data set
calibrationvoltage = [476,378,315,289,275,264]
calibrationrange = [20,30,40,50,60,70]
#calibration polynomial best fit
polydegrees = numpy.polyfit(calibrationvoltage,calibrationrange,2)
#Try to establish serial, print if fails
try:
    ser = serial.Serial('/dev/ttyACM0', 9600)
except:
    print "Could not open serial communication"
    quit()

while trigger == True: #ends when the scanner is done
    try:
        casedata = ser.readline()#reads the serial data
        print casedata #diagnostic, remove
    except:
        print "No Data avaliable"  #handle serial read errors
    else:
        if casedata == "end\r\n":  #if scanner is done
            pickle.dump(data, open('save.p','wb')) #write data to file for later
            for line in data:  #iterate thru data except 'end' string
                line=line.replace("\r\n","")  #remove string escapes
                line = line.split(';')   #split by index
                print line[2] #program is verbose for diagnostics
                if float(line[2]) <= 264 or float(line[2]) >= 476: #checks for points outside of calibration curve
                    print "Bad point"  #lets the user know if it throws out point
                else:
                    #convert from voltage to sensor range
                    sensorrange = polydegrees[0]*float(line[2])**2 +polydegrees[1]*float(line[2]) + polydegrees[2]
                    print sensorrange
                    #convert from spherical to cartesian
                    x = float(sensorrange)*math.cos(math.radians(float(line[1])))*math.sin(math.radians(float(line[0])*3))  #Convert to cartesian coords
                    y = float(sensorrange)*math.sin(math.radians(float(line[0])*3))*math.sin(math.radians(float(line[1])))
                    z = float(sensorrange)*math.cos(math.radians(float(line[0])*3))
                    xdata.append(x)  #write data
                    ydata.append(y)
                    zdata.append(z)
            ax.scatter(ydata, xdata,zdata, zdir='z') #plot
            #set axes and scale
            ax.set_xlim3d(0,100)
            ax.set_zlim3d(0,100)
            ax.set_ylim3d(0,100)
            plt.show() #show plot
            trigger = False #tell python to stop reading
            ser.close() #close serial
            serial.close('dev/ttyACM0')
        elif isinstance(casedata, basestring) and len(string.split(casedata,";")) == 3: #If data is in format we expect, write data
            data.append(casedata)
        else:           #otherwise, write no data
            time.sleep(0.05)
            print "No data avaliable"

                                            
    
