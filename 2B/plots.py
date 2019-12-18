import numpy as np
import matplotlib.pyplot as plt

filepath = "MEET.TXT"
data_in = open(filepath, "r")


datamatrix = np.genfromtxt(filepath)
filedata = data_in.readlines()

head = "   " + " ".join(
            [argument.ljust(15) for argument in filedata[0][1:].split("\t")]
        )

np.set_printoptions(
    formatter={
        "all": lambda x: str(" " + str(round(x, 3))).replace(" -", "-").ljust(15)
    },
    linewidth=150,
)
print(datamatrix)

meting = datamatrix[:,0]
meettijd = datamatrix[:,1]
temp = datamatrix[:,2]
pres = datamatrix[:,3]
humid = datamatrix[:,4] 

fig, ax1 = plt.subplots(num="figuur 1",figsize=(8,4))
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

plt.show()