import numpy
calibrationvoltage = [504,408,302,247,209,174,163,154]
calibrationrange = [20,30,40,50,60,70,80,90]
polydegrees = numpy.polyfit(calibrationvoltage,calibrationrange,2)
print polydegrees
