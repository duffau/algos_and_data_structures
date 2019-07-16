#include <stdio.h>
#include "utils.h"

void print_array(int array[], int len) {
	int i;
	printf("<");
	for (i=0; i<len; i++) {
		printf("%d", array[i]);
		if (i < len-1) {
			printf(" ");
		}
	}
	printf(">\n");
}

