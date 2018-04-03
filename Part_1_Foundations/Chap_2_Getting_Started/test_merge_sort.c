#include <stdio.h>
#include "utils.h"
#include "sorting_algos.h"


int main() {
	int a[] = {1, 4, 5, 6, 9}; 
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