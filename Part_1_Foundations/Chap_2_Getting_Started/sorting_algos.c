#include "sorting_algos.h"




void InsertionSort(int array[], int len) {
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

void ReversedInsertionSort(int array[], int len) {
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

