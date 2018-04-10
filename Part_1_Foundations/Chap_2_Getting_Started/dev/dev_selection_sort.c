#include <stdio.h>
#include "utils.h"
#include <limits.h>

void SelectionSort(int array[], int len);
int smallestElement(int array[], int start, int end);

int main(int argc, char const *argv[])
{
	
	int array1[] = {10, 5, 4, 6, 3, 2, 1};
	int len1 = sizeof(array1)/sizeof(array1[0]);
	int s;
	s = smallestElement(array1, 1, 4);
	printf("smallestElement(%s): %s[%d] = %d\n", "array1", "array1",s, array1[s]);
	print_array(array1, len1);
	SelectionSort(array1, len1);
	print_array(array1, len1);	
	return 0;
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