../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.factorize.o: factorize.c
	gcc -c factorize.c -o .factorize.o

factorize: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .factorize.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .factorize.o -o ../../../WORKBENCH/factorize
