#include <stdio.h>
#include "utils.h"
//#include "sorting_algos.h"


void InsertionSort(int array[], int len);
void BinaryInsertionSort(int array[], int len);
int binarySearchUpperBound(int array[], int start, int end, int value);

int main() {

	int len; 
	
	int a[] = {1, 4, 5, 6, 9}; 
	len = arrayLength(a);
	printf("\nInsertion Sort\n");
	printf("Input: ");
	print_array(a, len);
	InsertionSort(a, len);
	printf("Output: ");
	print_array(a, len);

	int aa[] = {1, 4, 5, 6, 9}; 
	len = arrayLength(aa);
	printf("\nBinary Insertion Sort\n");
	printf("Input: ");
	print_array(aa, len);
	BinaryInsertionSort(aa, len);
	printf("Output: ");
	print_array(aa, len);

	int b[] = {5, 4, 3, 2}; 
	len = arrayLength(b);
	printf("\nInsertion Sort\n");
	printf("Input: ");
	print_array(b, len);
	InsertionSort(b, len);
	printf("Output: ");
	print_array(b, len);
	
	int bb[] = {5, 4, 3, 2}; 
	len = arrayLength(bb);
	printf("\nBinary Insertion Sort\n");
	printf("Input: ");
	print_array(bb, len);
	BinaryInsertionSort(bb, len);
	printf("Output: ");
	print_array(bb, len);

	int c[] = {1,8, 5, 4, 10, 3, 2, 10, 11, 4}; 
	len = arrayLength(c);
	printf("\nInsertion Sort\n");
	printf("Input: ");
	print_array(c, len);
	InsertionSort(c, len);
	printf("Output: ");
	print_array(c, len);
	
	int cc[] = {1,8, 5, 4, 10, 3, 2, 10, 11, 4}; 
	len = arrayLength(cc);
	printf("\nBinary Insertion Sort\n");
	printf("Input: ");
	print_array(cc, len);
	BinaryInsertionSort(cc, len);
	printf("Output: ");
	print_array(cc, len);

	
}

void InsertionSort(int array[], int len) {
	int i, j, key;
	for (j=1; j<len; j++) {
		key = array[j];
		i = j - 1;
//		printf("j: %d\n", j);
//		printf("key: %d\n", key);
//		print_array(array, len);
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
//		printf("j: %d\n", j);
//		printf("key: %d\n", k);
//		printf("Least upper bound: %d\n", k);
		for (l=i; l >= k; l--) {
			array[l+1] = array[l];			
		}
		array[k] = key;
		print_array(array, len);
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
