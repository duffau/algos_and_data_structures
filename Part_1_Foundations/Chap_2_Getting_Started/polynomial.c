#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"


float PolynomialHorner(float coef[], int degree, float x){
	int i;
	float y = 0.0;
	for (i=degree-1; i!=0; i--) {
		y = coef[i] + x*y;
	}
	return y;
}

float PolynomialNaive(float coef[], int degree, float x){
	int i;
	int j;
	float y = 0.0;
	float x_temp = 1.0;
	for (i=0; i<degree; i++){
		for (j=0; j<i; j++) {
			x_temp *= x;
		}
		y += x_temp*coef[i];
		x_temp = 1.0;
	}
	return y;
}

float PolynomialIterative(float coef[], int degree, float x){
	int i;
	float y = 0.0;
	float x_temp = 1.0;
	for (i=0; i<degree; i++){
		y += x_temp*coef[i];
		x_temp *= x;
	}
	return y;
}
