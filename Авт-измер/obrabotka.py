import numpy as np
import matplotlib.pyplot as plt

with open("data.txt", "r") as data:
    tmp = [int(i) for i in data.read().split("\n")]
data_array = np.array(tmp)
num = np.arange(1, 192)
time_array = num*(1/23.731946900172023)
napr_array = data_array*0.0129

plt.plot(time_array, napr_array, marker = "*", label = "V(t)", markevery=10, color = "red", mec = "blue",
         fillstyle = "full", markersize = "5", mfc = "blue")
plt.minorticks_on()
plt.xlabel(r'$x$', fontsize=16)

print(time_array[190] - time_array[177])
plt.xlim([0, 9])
plt.ylim([0, 3])
plt.grid(which='major')
plt.grid(which='minor', linestyle=':')
plt.tight_layout()
plt.xlabel('Время, с', fontsize=10)
plt.ylabel('Напряжение, В', fontsize=10)
plt.title("Поцесс заряда и разряда конденсатора в RC-цепочке")
plt.text(6, 1.2, 'Время заряда = 7.5c', style='italic',
         bbox={'facecolor': 'b', 'alpha': 0.1, 'pad': 5})
plt.text(6, 1, 'Время разряда = 0.55', style='italic',
         bbox={'facecolor': 'b', 'alpha': 0.1, 'pad': 5})

plt.savefig("график.png")
plt.legend()
plt.show()