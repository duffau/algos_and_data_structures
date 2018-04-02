#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {

	int j, len;
	int *tmp;
	
	len = 10;
	int *array = malloc(len * sizeof *array);
	print_array(array, len);

	for (j=0; j<len; j++) {
		array[j] = len-j;
	}
	printf("%d\n", len);
	print_array(array, len);

	len = 11;
	tmp = realloc(array, 11 * sizeof *array);
	
	if (!tmp) {
	  printf("Error in reallocating memory for array \n");
	} else {
	  array = tmp;
	  print_array(array, len);
	}

	return 0;
}