#!/bin/bash
make
./binary_addition.o
./time_polynomial_eval.o
./time_sorting_algos.o
./venv/bin/python ./src/plot_time_measurments.py
