#include <stdio.h>
#include "utils.h"

void BubbleSort(int array[], int len);

int main(int argc, char const *argv[])
{
	int array[] = {7,2,5,1,2,1,1,9,6};
	int len = arrayLength(array);
	BubbleSort(array, len);
	print_array(array, len);
	checkSortedArray(array, len);
	return 0;
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