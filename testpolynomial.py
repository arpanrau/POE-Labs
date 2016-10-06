import numpy
import matplotlib.pyplot as plt


calibrationvoltage = [476,378,315,289,275,264]
calibrationrange = [20,30,40,50,60,70]
polydegrees = numpy.polyfit(calibrationvoltage,calibrationrange,2)

plt.scatter(calibrationvoltage, calibrationrange)
plt.show

print polydegrees
