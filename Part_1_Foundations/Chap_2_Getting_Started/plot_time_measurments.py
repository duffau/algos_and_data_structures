import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv("time_measurments.csv")

print(df)


fig, ax = plt.subplots()

for name, group in df.groupby(by='name'):
	group.plot(x='size', y='avg_time', ax=ax, label=name)


plt.title("Worst case timing")
plt.xlabel("Array size")
plt.ylabel("Average time (sec)")
# plt.show()
plt.savefig("time_measurments.png")