#include <stdio.h>

int binarySearch(int array[], int start, int end, int value);
int linearSearch(int array[], int start, int end, int value);

int main() {
	int array[] = {2, 3, 5, 7, 9, 11, 25, 27};
	printf("linearSearch of 9: %d\n", array[linearSearch(array, 0, 7, 9)]);
	printf("linearSearch of 2: %d\n", array[linearSearch(array, 0, 7, 2)]);
	printf("linearSearch of 27: %d\n", array[linearSearch(array, 0, 7, 27)]);
	printf("binarySearch of 9: %d\n", array[binarySearch(array, 0, 7, 9)]);
	printf("binarySearch of 2: %d\n", array[binarySearch(array, 0, 7, 2)]);
	printf("binarySearch of 27: %d\n", array[binarySearch(array, 0, 7, 27)]);
	printf("binarySearch of 11: %d\n", array[binarySearch(array, 0, 7, 11)]);
	printf("binarySearch of 25: %d\n", array[binarySearch(array, 0, 7, 25)]);

	printf("linearSearch of 15: %d\n", linearSearch(array, 0, 7, 15));
	printf("binarySearch of 15: %d\n", binarySearch(array, 0, 7, 15));

}

int binarySearch(int array[], int start, int end, int value) {
	if ( start<= end) {
		int mid = start + (end - start)/2;
		if (array[mid] == value) {
			return mid;
		} else if (array[mid] > value) {
			return binarySearch(array, start, mid-1, value);
		} else {
			return binarySearch(array, mid+1, end, value);
		}

	}
	return start;
}

int linearSearch(int array[], int start, int end, int value) {
	int i=0;
	while(array[i] < value) {
		i++;
	}
	return i;
}