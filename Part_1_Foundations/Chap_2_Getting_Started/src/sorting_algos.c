#include "sorting_algos.h"
#include <limits.h>


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


void BinaryInsertionSort(int array[], int len) {
	int i, j, k, l, key;
	for (j=1; j<len; j++) {
		key = array[j];
		i = j - 1;
		k = binarySearchUpperBound(array, 0, i, key);
		for (l=i; l >= k; l--) {
			array[l+1] = array[l];			
		}
		array[k] = key;
	}
}


int binarySearchUpperBound(int array[], int start, int end, int value) {
	if (start <= end) {
		int mid = start + (end - start)/2;
		if (array[mid] == value) {
			return mid;
		} else if (array[mid] > value) {
			return binarySearchUpperBound(array, start, mid-1, value);
		} else {
			return binarySearchUpperBound(array, mid+1, end, value);
		}

	}
	return start;
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


void MergeSort(int array[], int len) {
	mergeSort(array, 0, len-1);
}

void mergeSort(int array[], int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end)/2 ;
		mergeSort(array, start, mid);
		mergeSort(array, mid+1, end);
		merge(array, start, mid, end);
	}

}

void merge(int array[], int start, int mid, int end) {
	int i, j, k;
	int n1 = mid - start + 1; 
	int n2 = end - mid;
	int left[n1+1], right[n2+1]; 

	for (i=0; i<n1; i++) {
		left[i] = array[start + i];
	}
	left[n1] = INT_MAX;

	for (i=0; i<n2; i++) {
		right[i] = array[mid + i + 1];
	}
	right[n2] = INT_MAX;

	i = 0;
	j = 0;
	for (k=start; k<=end; k++) {
		if(left[i] <= right[j]) {
			array[k] = left[i];
			i += 1;
		} else {
			array[k] = right[j];
			j += 1;
		}


	}
}

void SelectionSort(int array[], int len) {
	int i;
	int end = len-1;
	int temp_value;
	int temp_index;

	for (i=0; i<len; i++) {
		temp_value = array[i];
		temp_index = smallestElement(array, i, end);
		array[i] = array[temp_index];
		array[temp_index] = temp_value;
	}
}

int smallestElement(int array[], int start, int end) {
	int i;
	int index_of_smallest_element=start;
	for (i=start+1; i<end+1; i++) {
		if (array[i] < array[index_of_smallest_element]) {
			index_of_smallest_element = i;
		}
	}
	return index_of_smallest_element;
}

void BubbleSort(int array[], int len) {
	int i, j;
	int temp;
	for (i=0; i<len; i++) {
		for (j=len-1; j>0; j--) {
			if (array[j] <array[j-1]) {
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			}
		}
	}

}
