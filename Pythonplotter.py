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

try:
    ser = serial.Serial('/dev/ttyACM0', 9600) #opens serial communication. Arduino should start scanning here.
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
            pickle.dump(data, open('save.p','wb'))
            for line in data:  #iterate thru data except 'end' string
                line=line.replace("\r\n","")  #remove string escapes
                line = line.split(';')   #split by index
                print line[2]
                if float(line[2]) <= 264 or float(line[2]) >= 476:
                    print "potato"
                else:
                    sensorrange = polydegrees[0]*float(line[2])**2 +polydegrees[1]*float(line[2]) + polydegrees[2]
                    print sensorrange
                    x = float(sensorrange)*math.cos(math.radians(float(line[0])))*math.sin(math.radians(float(line[1])))  #Convert to cartesian coords
                    y = float(sensorrange)*math.sin(math.radians(float(line[0])))*math.sin(math.radians(float(line[1])))
                    z = float(sensorrange)*math.cos(math.radians(float(line[0])))
                    xdata.append(x)  #write data
                    ydata.append(y)
                    zdata.append(z)
            ax.scatter(xdata, zdata, zdir='z') #plot
            plt.show() #show plot
            trigger = False #tell python to stop reading
            ser.close() #close serial
            serial.close('dev/ttyACM0')
        elif isinstance(casedata, basestring) and len(string.split(casedata,";")) == 3: #If data is in format we expect, write data
            data.append(casedata)
        else:           #otherwise, write no data
            time.sleep(0.05)
            print "No data avaliable"

                                            
    
