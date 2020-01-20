import numpy as np
import matplotlib.pyplot as plt


def plotdata(matrix1, matrix2, num):
    millis1 = matrix1[:, 1]
    millis2 = matrix2[:, 1]
    CO21 = matrix1[:, 7]
    CO22 = matrix2[:, 7]
    secs1 = millis1 / 1000
    secs2 = millis2 / 1000
    fig, ax1 = plt.subplots(figsize=(8, 4), num=num)

    (l1,) = ax1.plot(secs1, CO21, label="CO2 1", color="blue", ls="-")
    (l2,) = ax1.plot(secs2, CO22, label="CO2 2", color="red", ls="-")

    ax1.set_xlabel("$t$ (s)")
    ax1.set_ylabel("geluidssterkte")
    plt.grid()
    ax1.legend([l1, l2], ["zonder geluidsmuur", "met geluidsmuur"])
    plt.savefig(num)


filepathmet = "metgeluidsmuur.txt"
filepathzonder = "zondergeluidsmuur.txt"

datamet = np.genfromtxt(filepathmet)
datazonder = np.genfromtxt(filepathzonder)

plotdata(datazonder, datamet, "beideMic")

plt.show()
