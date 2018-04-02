#include <stdio.h>
#include <limits.h>
#include "utils.h"
//#include "sorting_algos.h"

void MergeSort(int array[], int len);
void mergeSort(int array[], int startsplit, int endsplit);
void merge(int array[], int startsplit, int splitpoint, int endsplit);

void MergeSort(int array[], int len) {
	mergeSort(array, 0, len);
}

void mergeSort(int array[], int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end)/2 ;
		printf("split point: %d\n", splitpoint);
		mergeSort(array, start, splitpoint);
		mergeSort(array, mid+1, end);
		merge(array, start, splitpoint, end);
	}

}

void merge(int array[], int start, int mid, int end) {
	int i, j, k;
	int n1 = mid - start + 1; 
	int n2 = end - mid;
	int left[n1+1], right[n2+1]; 
	
	printf("n1 = %d\n", n1);
	printf("n2 = %d\n", n2);
	for (i=0; i<n1; i++) {
		left[i] = array[start + i];
	}
	left[n1] = INT_MAX;
	printf("left array:");
	print_array(left, n1+1);	

	for (i=0; i<n2; i++) {
		right[i] = array[mid + i + 1];
	}
	right[n2] = INT_MAX;
	printf("right array:");
	print_array(right, n2+1);

	i = 0;
	j = 0;
	for (k=start; k<=end; k++) {
		if(left[i] <= right[j]) {
			array[k] = left[i++];
		} else {
			array[k] = right[j++];
		}


	}
	printf("array:");
	print_array(array, 5);
	printf("\n");


}


int main() {
	int a[] = {1, 2, 3, 4 ,5}; 
	int a_len = arrayLength(a);
	printf("\nMerge Sort\n");
	printf("Input: ");
	print_array(a, a_len);
	MergeSort(a, a_len);
	printf("Output: ");
	print_array(a, a_len);

	int b[] = {5, 4, 3, 2}; 
	int b_len = arrayLength(b);
	printf("\nMerge Sort\n");
	printf("Input: ");
	print_array(b, b_len);
	MergeSort(b, b_len);
	printf("Output: ");
	print_array(b, b_len);

	int c[] = {8, 7, 6, 5 ,4 ,3 ,2 ,1}; 
	int c_len = arrayLength(c);
	printf("\nMerge Sort\n");
	printf("Input: ");
	print_array(c, c_len);
	MergeSort(c, c_len);
	printf("Output: ");
	print_array(c, c_len);
}