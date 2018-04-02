#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "sorting_algos.h"


int main(int argc, char** argv) {
	float time_spent;
	int i, j, size, k;
	const int reps = 100;
	int sizes[argc-1];

	for (i=0; i<argc-1; i++) {
		sizes[i] = atoi(argv[i+1]);
	} 

	int sizes_len = sizeof(sizes) / sizeof(sizes[0]);
	size = sizes[0];
	int *dynarray = malloc(size * sizeof *dynarray);
	float avg_time;
	int avg_count;

	printf("\nTiming insertion sort\n");
	printf("Array sizes chosen: ");
	print_array(sizes, sizes_len);
	FILE *csvfile = fopen("insertion_sort.dat", "w");
	if (csvfile == NULL) {
		printf("Error opening .dat file!");
		exit(1);
	}
	
	for(k=0; k < sizes_len; k++) {
		size = sizes[k];
		dynarray = realloc(dynarray, size * sizeof *dynarray);	
		avg_time = 0.0;
		avg_count = 0;
		for(i=0; i < reps; i++) {
			for (j=0; j<size; j++) {
				dynarray[j] = size-j;
			}
			clock_t begin = clock();
			InsertionSort(dynarray, size);
			clock_t end = clock();
			time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
			mean(time_spent, &avg_time, &avg_count);
		}
		printf("Average time spent: %.3e over %d reps for array of size %d\n", avg_time, reps, size);
		fprintf(csvfile, "%d %e\n", size, avg_time);
	}
	fclose(csvfile);
	
	return 0;
}




