#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "sorting_algos.h"

void timeSortingAlgoWorstCase(void (*sortingAlgo)(int*, int), char *name, FILE *csvfile, int sizes[], int sizes_len, int reps);
void checkSortedArray(int array[], int len);

int main(int argc, char** argv) {
	const int reps = 100;
	int sizes[argc-1];
	int i;

	for (i=0; i<argc-1; i++) {
		sizes[i] = atoi(argv[i+1]);
	} 

	int sizes_len = sizeof(sizes) / sizeof(sizes[0]);

	printf("Timing sorting algos\n");
	printf("Array sizes chosen: ");
	print_array(sizes, sizes_len);

	FILE *csvfile; 
	csvfile = fopen("time_measurments.csv", "w");
	fprintf(csvfile, "size,avg_time,name\n");
	fclose(csvfile);
	csvfile = fopen("time_measurments.csv", "a");

	if (csvfile == NULL) {
		printf("Error opening csv file!");
		exit(1);
	}
	timeSortingAlgoWorstCase(*InsertionSort, "insertion_sort", csvfile, sizes, sizes_len, reps);
	timeSortingAlgoWorstCase(*MergeSort, "merge_sort", csvfile, sizes, sizes_len, reps);
	timeSortingAlgoWorstCase(*BinaryInsertionSort, "binary_insertion_sort", csvfile, sizes, sizes_len, reps);
	fclose(csvfile);

	
	return 0;
}



void timeSortingAlgoWorstCase(void (*sortingAlgo)(int*, int), char *name, FILE *csvfile, int sizes[], int sizes_len , int reps) {
	float time_spent, avg_time;
	clock_t begin, end;
	int i, j, size, k, avg_count;
	
	size = sizes[0];
	int *dynarray = malloc(size * sizeof *dynarray);
	printf("\nTiming %s\n", name);
	for(k=0; k < sizes_len; k++) {
		size = sizes[k];
		dynarray = realloc(dynarray, size * sizeof *dynarray);	
		avg_time = 0.0;
		avg_count = 0;
		for(i=0; i < reps; i++) {
			for (j=0; j<size; j++) {
				dynarray[j] = size-j;
			}
			begin = clock();
			(*sortingAlgo)(dynarray, size);
			end = clock();
			checkSortedArray(dynarray, size);
			time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
			mean(time_spent, &avg_time, &avg_count);
		}
		printf("Average time spent: %.3e over %d reps for array of size %d\n", avg_time, reps, size);
		fprintf(csvfile, "%d, %e, %s\n", size, avg_time, name);
	}
}

void checkSortedArray(int array[], int len) {
	int i;

	for (i=0; i<len-1; i++) {
		if (array[i] <= array[i+1]) {

		} else  {
			printf("Array is not sorted.\n");
			print_array(array, len);
			exit(1);
		}
	}
}