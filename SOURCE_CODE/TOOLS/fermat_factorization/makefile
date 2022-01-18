../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.fermat_factorization.o: fermat_factorization.c
	gcc -c fermat_factorization.c -o .fermat_factorization.o

fermat_factorization: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .fermat_factorization.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .fermat_factorization.o -o ../../../WORKBENCH/fermat_factorization
