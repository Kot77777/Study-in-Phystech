#объемный расход: dv_dt
import numpy as np
import matplotlib.pyplot as plt

dv_dt1 = 0.158
I1 = np.array([125.77, 177.32, 251.2, 270.1])#мА
U1 = np.array([3.711, 5.237, 7.192, 7.736])#В
e1 = np.array([0.068, 0.143, 0.293, 0.336])#мВ
N = I1*U1

dv_dt2 = 0.06
I2= np.array([75.12, 102.18, 126.13, 117.92])#мА
U2 = np.array([2.214, 3.014, 3.722, 3.48])#В
e2 = np.array([0.55, 0.103, 0.142, 0.124])#мВ

fig, ax = plt.subplots()

t = np.polyfit(dT, N, 1)
f = np.poly1d(t)

plt.scatter(T, R, c="r", zorder = 1)
plt.plot(T, f(T),
         linestyle='-', alpha = 1,
         color = "b", ms=5, zorder = 0)
plt.grid(linewidth = 0.5)

plt.show()