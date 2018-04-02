#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int count = 6;
	double x[10] = {1.,2.,3.,4.,5.,6.};
	double y[10] = {1.,4.,9.,16.,25.,36.};

	FILE *gnuplot = popen("gnuplot", "w");
	fprintf(gnuplot, "set terminal png\n");
	fprintf(gnuplot, "set terminal png\n");	
	fprintf(gnuplot, "set title 'Worst case timing of Insertion Sort'\n");
	fprintf(gnuplot, "set xlabel 'Array size'\n");
	fprintf(gnuplot, "set ylabel 'Average execution time'\n");

	fprintf(gnuplot, "set output 'plot.png'\n");
	fprintf(gnuplot, "plot '-'\n");
	for (i = 0; i < count; i++) {
	    fprintf(gnuplot, "%g %g\n", x[i], y[i]);
	}
	fprintf(gnuplot, "e\n");
	fflush(gnuplot);
}

