import numpy as np
import matplotlib.pyplot as plt
#plt.gca().set_aspect('equal')

k = np.linspace(-np.pi, np.pi, 1000)
x = np.cos(k)/0.81
y = np.sin(k)/0.25

fig, ax = plt.subplots()
ax.scatter(x,y)

ax.set_xbound(-5,5)
ax.set_ybound(-5,5)
ax.set_box_aspect(1)

#plt.plot(x, y)
plt.show()
