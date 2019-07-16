# Algorithms and Data Structures

This repo contains C programs and exercise answers, which are the result of my self-study of _Introduction to Algorithms_ by Cormen, Leiserson, Rivest & Stein. The idea is to learn about the theoretical aspects of the algorithms and at the same time learn to implement them in C.


## Part 1 - Foundations

### Chapter 2 - Getting Started

#### Sorting algorithms
![Sorting algos worst case timings](https://raw.githubusercontent.com/duffau/algos_and_data_structures/master/Part_1_Foundations/Chap_2_Getting_Started/png/sorting_algos_time_measurments.png)

In the plot you see timings of C implementations of different sorting algorithms from the first chapter of Cormen et al. All algortims where timed on a collection of arrays in reverse order, so arrays on the form `[5, 4, 3, 2, 1]`. 

#### Horner's Rule
![Sorting algos worst case timings](https://raw.githubusercontent.com/duffau/algos_and_data_structures/master/Part_1_Foundations/Chap_2_Getting_Started/png/poly_algos_time_measurments.png)

Using Horners rule, that is exploiting that a polynomial can be computed as, 
```
y = a0 + a1*x + a2*x^2 + ... + an*x^n
  = a0 + x*(a1 + x*(a2 + ... + x*(an-1 + an*x^n) ... ))
```
it's possible to evaluate a Polynomial in linear time, instead of quadratic running time of a naive implementation.

### Chapter 3 - Growth of functions

See [here](https://github.com/duffau/algos_and_data_structures/blob/master/Part_1_Foundations/Chap_3_Growth_of_functions).

