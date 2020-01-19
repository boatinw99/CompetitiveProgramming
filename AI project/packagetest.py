import matplotlib.pyplot as plt
import numpy as np
x = np.linspace(0, 20, 100)  # Create a list of evenly-spaced numbers over the range
plt.plot(x, x*2)       # Plot the sine of each x point
a = [1,4,5]
b = [3,5,6]
plt.scatter(a,b)
plt.show()  