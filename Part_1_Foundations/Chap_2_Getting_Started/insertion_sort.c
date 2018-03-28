#include <stdio.h>
#include <time.h>
#include "utils.h"

void insertion_sort(int array[], int len);
void reversed_insertion_sort(int array[], int len);
void print_array(int array[], int len);

int main() {
	
	int a[] = {1, 2, 3, 4 ,5}; 
	int a_len = sizeof(a) / sizeof(a[0]);
	printf("\nInsertion Sort\n");
	printf("Input: ");
	print_array(a,  a_len);
	insertion_sort(a, a_len);
	printf("Output: ");
	print_array(a,  a_len);

	int b[] = {3, 1, 4, 2, 5}; 
	int b_len = sizeof(b) / sizeof(b[0]);
	printf("\nInsertion Sort\n");
	printf("Input: ");
	print_array(b,  b_len);
	insertion_sort(b, b_len);
	printf("Output: ");
	print_array(b,  b_len);
	
	int c[] = {1, 2, 3, 4 ,5}; 
	int c_len = sizeof(c) / sizeof(c[0]);
	printf("\nReversed insertion Sort\n");
	printf("Input: ");
	print_array(c,  c_len);
	reversed_insertion_sort(c, c_len);
	printf("Output: ");
	print_array(c,  c_len);

	printf("\nTiming insertion sort\n");
	float time_spent;
	int i, j, size;
	int reps = 10;
	int sizes[] = {10, 100, 500, 1000, 5000, 10000, 20000, 50000};
	int array[size];

	int sizes_len = sizeof(sizes) / sizeof(sizes[0]);
	for(k=0; k < sizes_len; k++) {
		size = sizes[k];	
		for(i=0; i < reps; i++) {
			for (j=0; j<size; j++) {
				array[j] = size-j;
			}
			print_array(array, size);
			clock_t begin = clock();
			insertion_sort(array, size);
			clock_t end = clock();
			print_array(array, size);
			time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
			printf("time spent: %.3f\n", time_spent);
		}
	}
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


