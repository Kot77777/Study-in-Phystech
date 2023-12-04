import numpy as np
import matplotlib.pyplot as plt

I = np.array([0.0182, 0.0159, 0.0131, 0.02201])
R_kv = (np.array([0.17, 0.15, 0.13, 0.18]))**2

fig, ax = plt.subplots()

t1 = np.polyfit(R_kv, I, 1)
f1 = np.poly1d(t1)

plt.scatter(R_kv, I, c="r")
plt.plot(R_kv, f1(R_kv), label = 'I = 0.535R^2 + 0.0038',
         linestyle='-', mfc = 'r', alpha = 1,
         color = 'blue', ms=5)
plt.grid(linewidth = 0.5)
plt.xlabel('R^2, м^2', fontsize=10)
plt.ylabel('I, кг*м^2', fontsize=10)

plt.legend()

beta = np.array([0.669, 1.067, 1.658, 1.907, 2.3])
M = np.array([0.0121, 0.0189, 0.026, 0.031, 0.037])

fig1, ax = plt.subplots()

t1 = np.polyfit(M, beta, 1)
f1 = np.poly1d(t1)

plt.scatter(M, beta, c="r")
plt.plot(M, f1(M), label = '\u03B2_0 = 66.46M - 0.14',
         linestyle='-', mfc = 'r', alpha = 1,
         color = 'blue', ms=5)
plt.grid(linewidth = 0.5)
plt.xlabel('M, Н*м', fontsize=10)
plt.ylabel('\u03B2_0, рад/c^2', fontsize=10)

plt.legend()
plt.show()

