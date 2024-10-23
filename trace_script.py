import numpy as np
import matplotlib.pyplot as plt

trace2 = np.load("PATH")
trace1 = np.load("PATH")

plt.figure(figsize=(10, 4))  
plt.plot(trace2, label="Inverted Offsetted")
plt.plot(trace1, label="Non-Inversion Offsetted")

plt.xlabel("Sampling Points")
plt.ylabel("Power Consumption")
plt.title("Inversion vs Non-Inversion (Offsetted)")
plt.legend()
plt.xlim(200, 250)
plt.show()
# 
# plt.savefig("second_method_properly_overlayed.svg", format="svg")

#full_trace24k.svg 

