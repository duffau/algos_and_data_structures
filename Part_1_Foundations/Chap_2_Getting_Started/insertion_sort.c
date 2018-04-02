#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"


void insertion_sort(int array[], int len);
void reversed_insertion_sort(int array[], int len);

int main() {
	const char *algo_name = "insertion_sort";
	int a[] = {1, 2, 3, 4 ,5}; 
	int a_len = arrayLength(a);
	printf("\nInsertion Sort\n");
	printf("Input: ");
	print_array(a, a_len);
	insertion_sort(a, a_len);
	printf("Output: ");
	print_array(a, a_len);

	int b[] = {3, 1, 4, 2, 5}; 
	int b_len = arrayLength(b);
	printf("\nInsertion Sort\n");
	printf("Input: ");
	print_array(b, b_len);
	insertion_sort(b, b_len);
	printf("Output: ");
	print_array(b, b_len);
	
	int c[] = {1, 2, 3, 4 ,5}; 
	int c_len = arrayLength(c);
	printf("\nReversed insertion Sort\n");
	printf("Input: ");
	print_array(c, c_len);
	reversed_insertion_sort(c, c_len);
	printf("Output: ");
	print_array(c, c_len);

	printf("\nTiming insertion sort\n");
	float time_spent;
	int i, j, size, k, reps;
	reps = 100;
	int sizes[] = {10, 50, 100, 200, 300, 400, 500, 1000, 2500, 5000};
	//int sizes[] = {10, 20, 30};
	int sizes_len = sizeof(sizes) / sizeof(sizes[0]);
	size = sizes[0];
	int *dynarray = malloc(size * sizeof *dynarray);
	float avg_time;
	int avg_count;
	
	FILE *csvfile = fopen("time_measurments.csv", "w");
	if (csvfile == NULL) {
		printf("Error opening csv file!");
		exit(1);
	}
	fprintf(csvfile, "size, avg_time, algo_name\n");
	
	for(k=0; k < sizes_len; k++) {
		size = sizes[k];
		dynarray = realloc(dynarray, size * sizeof *dynarray);	
		for(i=0; i < reps; i++) {
			for (j=0; j<size; j++) {
				dynarray[j] = size-j;
			}
			//print_array(dynarray, size);
			clock_t begin = clock();
			insertion_sort(dynarray, size);
			clock_t end = clock();
			//print_array(dynarray, size);
			time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
			//printf("time spent: %.3e, rep: %d\n", time_spent, i+1);
			mean(time_spent, &avg_time, &avg_count);
		}
		printf("Average time spent: %.3e over %d reps for array of size %d\n", avg_time, reps, size);
		fprintf(csvfile, "%d, %e, %s\n", size, avg_time, algo_name);
		avg_time = 0.0;
		avg_count = 0;
	}
	fclose(csvfile);
	
	return 0;
}

void insertion_sort(int array[], int len) {
	int i, j, key;
	for (j=1; j<len; j++) {
		key = array[j];
		i = j - 1;
		while (i > -1 && array[i] > key) {
			array[i+1] = array[i];
			i -= 1;
		}
		array[i + 1] = key;
	}
}

void reversed_insertion_sort(int array[], int len) {
	int i, j, key;
	for (j=1; j<len; j++) {
		key = array[j];
		i = j - 1;
		while (i > -1 && array[i] < key) {
			array[i+1] = array[i];
			i -= 1;
		}
		array[i + 1] = key;
	}
}


