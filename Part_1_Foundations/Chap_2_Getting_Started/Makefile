
all: binary_addition time_polynomial_eval time_sorting_algos

binary_addition: src/binary_addition.c 
	gcc -o binary_addition.o src/binary_addition.c

time_polynomial_eval: src/time_polynomial_eval.c src/utils.c src/polynomial.c
	gcc -o time_polynomial_eval.o src/time_polynomial_eval.c src/utils.c src/polynomial.c

time_sorting_algos: src/time_sorting_algos.c src/utils.c src/sorting_algos.c
	gcc -o time_sorting_algos.o src/time_sorting_algos.c src/utils.c src/sorting_algos.c
