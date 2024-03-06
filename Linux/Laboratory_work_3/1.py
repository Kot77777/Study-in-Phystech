import numpy as np

sp = []
with open("RES.txt", "r") as file1:
    # итерация по строкам
    for line in file1:
        sp.append(list(map(int, line.split())))
sp.append([i for i in range(128640)])
#print((sp[128]))


import numpy as np




