#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void mean(float x, float *current_mean, int *count) {
	*current_mean = *current_mean + (x - *current_mean)/(*count+1);
	*count += 1;
}

void print_array(int array[], int len) {
	int i;
	printf("<");
	for (i=0; i<len; i++) {
		printf("%d", array[i]);
		if (i < len-1) {
			printf(" ");
		}
	}
	printf(">\n");
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