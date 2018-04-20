#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main(int argc, char const *argv[])
{
	int i;
	time_t t;
	int degree = atoi(argv[1]);
	float coef[degree];

	int a = 10;
	srand((unsigned) time(&t));

	for (i=0; i<degree; i++) {
		coef[i] = (float)rand()/(float)(RAND_MAX/a);
	}

	float x = (float)rand()/(float)(RAND_MAX/a);
	printf("PolynomialHorner(%f) = %f\n", x, PolynomialHorner(coef, degree, x));
	printf("PolynomialNaive(%f) = %f\n", x, PolynomialNaive(coef, degree, x));
	printf("PolynomialIterative(%f) = %f\n", x, PolynomialIterative(coef, degree, x));
	return 0;
}