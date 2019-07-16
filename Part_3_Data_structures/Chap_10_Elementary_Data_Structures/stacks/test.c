#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stacks.h"
#include "utils.c"

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define make_green(s) ANSI_COLOR_GREEN s ANSI_COLOR_RESET
#define passed(s) make_green("passed") ": " s "\n"

// void print_passed(char *s) {
// 	printf(make_green("passed") s  "\n");
// }

int main(int argc, char const *argv[])
{	

	struct Stack* make_stack_fixture() {
		struct Stack* stack = malloc(sizeof(struct Stack));
		(*stack).capacity = 3;
		(*stack).top = -1;
		(*stack).array = malloc(3 * sizeof(int));
		return stack;		
	}

	void test_equal() {
		struct Stack* stack1 = make_stack_fixture();
		struct Stack* stack2 = make_stack_fixture();
		for (int i=0; i<3;i++) {
			(*stack1).array[i] = 1;
			(*stack2).array[i] = 1;
		}

		assert(equal(stack1, stack2));
		printf(passed("test_equal"));
	}
	test_equal();

	void test_create_stack() {
		struct Stack* expected_stack = make_stack_fixture();
		struct Stack* stack = createStack(3);

		assert(equal(stack, expected_stack));
		printf(passed("test_create_stack "));		
	}
	test_create_stack();

	void test_is_full_empty_stack() {
		struct Stack* stack = make_stack_fixture();

		assert(isfull(stack) == 0);
		printf(passed("test_is_full_empty_stack"));
	}
	test_is_full_empty_stack();

	void test_is_full_on_full_stack() {
		struct Stack* stack = make_stack_fixture();
		(*stack).top = 2;

		assert(isfull(stack));
		printf(passed("test_is_full_on_full_stack"));
	}
	test_is_full_on_full_stack();

	void test_push() {
		struct Stack* stack = make_stack_fixture();
		push(stack, 42);

		assert((*stack).array[0] == 42);
		assert((*stack).top == 0);
		printf(passed("test_push"));
	}
	test_push();

	void test_push_full_stack() {
		struct Stack* stack = make_stack_fixture();
		(*stack).top = 2;
		int last_value_before_push = (*stack).array[2];
		push(stack, 42);

		assert((*stack).array[2] == last_value_before_push);
		assert((*stack).top == 2);
		printf(passed("test_push_full_stack"));
	}
	test_push_full_stack();

	
	void test_isempty_true() {
		struct Stack* stack = make_stack_fixture();

		assert(isempty(stack) == 1);		
		printf(passed("test_isempty_true"));
	}
	test_isempty_true();

	void test_isempty_false() {
		struct Stack* stack = make_stack_fixture();
		push(stack, 42);

		assert(isempty(stack) == 0);		
		printf(passed("test_isempty_false"));
	}
	test_isempty_false();

	void test_pop() {
		struct Stack* stack = make_stack_fixture();
		(*stack).array[1] = 42;
		(*stack).top = 1;
		int item = pop(stack);

		assert(item == 42);
		assert(stack->top == 0);
		printf(passed("test_pop"));
	}
	test_pop();

	return 0;
}