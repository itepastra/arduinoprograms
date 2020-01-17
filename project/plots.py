import numpy as np
import matplotlib.pyplot as plt


def plotdata(matrix, num):
    # meting = matrix[:, 0]
    millis = matrix[:, 1]
    temp = matrix[:, 2]
    humid = matrix[:, 3]
    # pres = matrix[:, 4]
    CO2 = matrix[:, 5]
    secs = millis / 1000

    fig, ax1 = plt.subplots(figsize=(8, 4), num=num)
    fig.subplots_adjust(right=0.75)

    ax2 = ax1.twinx()
    ax3 = ax1.twinx()

    ax3.spines["right"].set_position(("axes", 1.2))
    ax3.spines["right"].set_visible(True)

    (l1,) = ax1.plot(secs, temp, label="temperatuur", color="red", ls="solid")
    (l2,) = ax2.plot(secs, CO2, label="CO2 concentratie", color="black", ls="dashed")
    (l3,) = ax3.plot(secs, humid, label="luchtvochtigheid", color="blue", ls="dotted")

    ax1.set_xlabel("$t$ (s)")
    ax1.set_ylabel("$T$ (C)")
    ax2.set_ylabel("CO2 concentratie")
    ax3.set_ylabel("relatieve luchtvochtigheid")

    ax1.legend([l1, l2, l3], ["temperatuur", "CO2 concentratie", "luchtvochtigheid"])
    plt.savefig(num)


filepathmet = "metgeluidsmuur.txt"
filepathzonder = "zondergeluidsmuur.txt"

datamet = np.genfromtxt(filepathmet)
datazonder = np.genfromtxt(filepathzonder)

plotdata(datamet, "met geluidsmuur")
plotdata(datazonder, "zonder geluidsmuur")

plt.show()
