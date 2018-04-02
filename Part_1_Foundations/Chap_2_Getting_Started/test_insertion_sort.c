#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "sorting_algos.h"

int main(void) {
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
}
