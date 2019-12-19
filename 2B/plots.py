import numpy as np
import matplotlib.pyplot as plt

def plotheader(str):
    pass

def plotdata(matrix):
    meting = matrix[:,0]
    meettijd = matrix[:,1]
    temp = matrix[:,2]
    pres = matrix[:,3]
    humid = matrix[:,4] 

    fig, ax1 = plt.subplots(figsize=(8,4))
    fig.subplots_adjust(right=0.75)

    ax2 = ax1.twinx()
    ax3 = ax1.twinx()

    ax3.spines['right'].set_position(("axes",1.2))
    ax3.spines['right'].set_visible(True)


    l1, = ax1.plot(meettijd, temp,label="temperatuur", color="red", ls='solid')
    l2, = ax2.plot(meettijd, pres,label="druk", color='black', ls="dashed")
    l3, = ax3.plot(meettijd,humid,label="luchtvochtigheid", color='blue', ls='dotted')

    ax1.set_xlim(0)
    ax2.set_xlim(0)
    ax3.set_xlim(0)

    ax1.set_xlabel("$t$ (ms)")
    ax1.set_ylabel('temperatuur')
    ax2.set_ylabel('druk')
    ax3.set_ylabel('relatieve luchtvochtigheid')

    ax1.legend([l1,l2,l3], ["temperatuur","druk","luchtvochtigheid"])






filepath = "MEETMEER.TXT"
data_in = open(filepath, "r")
temp=[]
for line in data_in:
    newblock=0
    if line[0] =="#":
        newblock=1
        plotheader(line)
    temp.append(line)
    if len(temp) > 2 and newblock==1:
        datamatrix = np.genfromtxt(temp)
        plotdata(datamatrix)
        temp=[]
        newblock=0

datamatrix = np.genfromtxt(temp)
plotdata(datamatrix)


plt.show()