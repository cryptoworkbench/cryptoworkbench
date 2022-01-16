../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.polynomial_function_over_a_GF.o: polynomial_function_over_a_GF.c
	gcc -c polynomial_function_over_a_GF.c -o .polynomial_function_over_a_GF.o

polynomial_function_over_a_GF: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .polynomial_function_over_a_GF.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .polynomial_function_over_a_GF.o -o ../../../WORKBENCH/polynomial_function_over_a_GF
