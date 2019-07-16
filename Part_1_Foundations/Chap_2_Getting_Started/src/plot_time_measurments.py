import os
import pandas as pd
import matplotlib.pyplot as plt

current_folder = os.path.dirname(os.path.realpath(__file__))

time_measurments = [
	("sorting_algos_time_measurments.csv", "Worst case timing of sorting algos"),
	("poly_algos_time_measurments.csv", "Timing of polynomial evaluation algos")
]

for filename, title in time_measurments:
	df = pd.read_csv(filename)

	# Rescaling seconds to miliseconds
	df['avg_time'] = df['avg_time']*1000

	fig, ax = plt.subplots()

	for name, group in df.groupby(by='name'):
		group.plot(x='size', y='avg_time', ax=ax, label=name)


	ax.set_title(title)
	ax.set_xlabel("Array size")
	ax.set_ylabel("Average time (milisec)")
	ax.ticklabel_format(style='sci', axis='y', scilimits=(-3, 3))
	plot_path = os.path.join(current_folder, "../png/{}.png".format(filename.replace('.csv', '')))
	plt.savefig(plot_path)
	print("Plot saved to : '{}'".format(plot_path))

