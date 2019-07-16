import pandas as pd
import matplotlib.pyplot as plt
time_measurments = [("sorting_algos_time_measurments.csv", "Worst case timing of sorting algos"),("poly_algos_time_measurments.csv", "Timing of polynomial evaluation algos")]
for filename, title in time_measurments:
	df = pd.read_csv(filename)

	# Rescaling seconds to miliseconds
	df['avg_time'] = df['avg_time']*1000

	print(df)


	fig, ax = plt.subplots()

	for name, group in df.groupby(by='name'):
		group.plot(x='size', y='avg_time', ax=ax, label=name)


	ax.set_title(title)
	ax.set_xlabel("Array size")
	ax.set_ylabel("Average time (milisec)")
	ax.ticklabel_format(style='sci', axis='y', scilimits=(-3, 3))
	# plt.show()
	plt.savefig("{}.png".format(filename.replace('.csv', '')))