#include <stdio.h>
#include "utils.h"
#include "sorting_algos.h"
#include <limits.h>

void MergeInsertionSort(int array[], int len);
void insertionSort(int array[], int start, int end);
void mergeInsertionSort(int array[], int start, int end);

int main(int argc, char const *argv[])
{
	int array1[] = {10, 5, 4, 6, 3, 2, 1};
	int len1 = sizeof(array1)/sizeof(array1[0]);
	print_array(array1, len1);	
	MergeInsertionSort(array1, len1);
	print_array(array1, len1);	

	int array2[] = {10, 5, 4, 6, 3, 2, 1};
	int len2 = sizeof(array2)/sizeof(array2[0]);
	print_array(array2, len2);	
	insertionSort(array2, 0, len2-1);
	print_array(array2, len2);	
	return 0;
}

void MergeInsertionSort(int array[], int len) {
	mergeInsertionSort(array, 0, len-1);
}


void mergeInsertionSort(int array[], int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end)/2;

		if (mid - start > 40) {
			mergeSort(array, start, mid);
		} else {
			insertionSort(array, start, mid);
			print_array(array, end);
		}

		if (end - mid + 1 > 40) {
			mergeSort(array, mid+1, end);
		} else {
			insertionSort(array, mid+1, end);
			print_array(array, end);
		}

		merge(array, start, mid, end);
	}

}


void insertionSort(int array[], int start, int end) {
	int i, j, key;
	for (j=start+1; j<end+1; j++) {
		key = array[j];
		i = j - 1;
		while (i > -1 && array[i] > key) {
			array[i+1] = array[i];
			i -= 1;
		}
		array[i + 1] = key;
	}
}