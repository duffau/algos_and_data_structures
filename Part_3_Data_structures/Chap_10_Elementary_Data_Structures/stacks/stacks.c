#include "stacks.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void print_stack(struct Stack* stack){
	printf("\ntop: %d\n capacity: %d\n array:\n", (*stack).top, (*stack).capacity);
	print_array((*stack).array, (*stack).capacity);
}

int equal(struct Stack* first, struct Stack* second) {
	if ((*first).top != (*second).top) {
		return 0;
	}
	if ((*first).capacity != (*second).capacity) {
		return 0;
	}
	for (int i=0; i < (*first).capacity; i++) {
		if ((*first).array[i] != (*second).array[i]) {
			return 0;
		}
	}
	return 1;
}

struct Stack* createStack(int capacity) {
	struct Stack* stack = malloc(sizeof(struct Stack));
	(*stack).capacity = capacity;
	(*stack).top = -1;
	(*stack).array = malloc(capacity * sizeof(int));
	return stack;		
}

int isfull(struct Stack* stack) {
	return (*stack).top == (*stack).capacity - 1;
} 

void push(struct Stack* stack, int item) {
	if (isfull(stack)) {
		return;
	}
	(*stack).array[++(*stack).top] = item;
}

int isempty(struct Stack* stack) {
	return (*stack).top == -1;
} 

int pop(struct Stack* stack) {
	if (isempty(stack)) {
		return INT_MIN;
	}
	return (*stack).array[(*stack).top--];
}

