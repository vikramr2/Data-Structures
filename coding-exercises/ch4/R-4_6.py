import matplotlib.pyplot as plt
import numpy as np

x = range(100)
y = [[], [], [], [], []]

for i in x:
    y[0].append(8*i)
    y[1].append(4*i*np.log10(i))
    y[2].append(2*i**2)
    y[3].append(i**3)
    y[4].append(2**i)

plt.loglog(x, y[0], x, y[1], x, y[2], x, y[3], x, y[4])
plt.show()
