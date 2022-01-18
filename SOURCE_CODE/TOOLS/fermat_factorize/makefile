../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.fermat_factorize.o: fermat_factorize.c
	gcc -c fermat_factorize.c -o .fermat_factorize.o

fermat_factorize: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .fermat_factorize.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .fermat_factorize.o -o ../../../WORKBENCH/fermat_factorize
