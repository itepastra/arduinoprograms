import numpy as np
import matplotlib.pyplot as plt


def plotdata(matrix1, matrix2, num):
    CO21 = matrix1[:, 5]
    CO22 = matrix2[:, 5]
    CO2both = [CO21, CO22]
    fig, ax1 = plt.subplots(figsize=(8, 4), num=num)

    ax1.violinplot(CO2both)
    plt.grid()
    plt.savefig(num)


filepathmet = "metgeluidsmuur.txt"
filepathzonder = "zondergeluidsmuur.txt"

datamet = np.genfromtxt(filepathmet)
datazonder = np.genfromtxt(filepathzonder)

plotdata(datazonder, datamet, "CO2vergelijking")

plt.show()
