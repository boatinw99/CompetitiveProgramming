# import pandas
import numpy as np
from numpy.polynomial.polynomial import polyfit
import matplotlib.pyplot as plt

# Sample data
x = np.array([3.10,3.05,3.00,2.96,2.92,2.87,2.83]) 
y = np.array([-1.2,-1.1,-0.967,-0.854,-0.752,-0.533,-0.452]) 

# Fit with polyfit
b, m = polyfit(x, y, 1)

plt.plot(x, y, '.')
plt.plot(x, b + m * x, '-')
plt.show()