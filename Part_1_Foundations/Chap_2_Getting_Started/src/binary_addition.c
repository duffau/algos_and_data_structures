#include <stdio.h>

void print_array(unsigned char array[], int len);

unsigned char xor(unsigned char a, unsigned char b) {
	return (a || b) && !(a && b);
}


int main() {
	printf("0 xor 0 = %d\n", xor(0, 0));
	printf("1 xor 0 = %d\n", xor(1, 0));
	printf("0 xor 1 = %d\n", xor(0, 1));
	printf("1 xor 1 = %d\n", xor(1, 1));

	unsigned char a[] = {1,1,1,1,0,1,0,1};
	unsigned char b[] = {1,1,1,1,0,0,0,1};
	unsigned char c[] = {0,0,0,0,0,0,0,0,0};
	unsigned char carry[] = {0,0,0,0,0,0,0,0,0};
	int len = 8;
	
	print_array(a, len);
	print_array(b, len);

	int i;
	for (i=0; i < len; i++) {
		carry[i+1] = a[i] && b[i];
		c[i] = xor(a[i], b[i]);
		c[i] = xor(c[i], carry[i]);
	}
	c[len] = carry[len];
	print_array(c, len+1);

	return 0;
}





void print_array(unsigned char array[], int len) {
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