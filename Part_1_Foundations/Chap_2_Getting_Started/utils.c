#include <stdio.h>
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