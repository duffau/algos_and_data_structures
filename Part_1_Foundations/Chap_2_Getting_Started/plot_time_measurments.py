import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv("time_measurments.csv")

# Rescaling seconds to miliseconds
df['avg_time'] = df['avg_time']*1000

print(df)


fig, ax = plt.subplots()

for name, group in df.groupby(by='name'):
	group.plot(x='size', y='avg_time', ax=ax, label=name)


ax.set_title("Worst case timing")
ax.set_xlabel("Array size")
ax.set_ylabel("Average time (milisec)")
ax.ticklabel_format(style='sci', axis='y', scilimits=(-3, 3))
# plt.show()
plt.savefig("time_measurments.png")