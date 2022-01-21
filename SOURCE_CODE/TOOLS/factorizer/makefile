../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.factorization_methods.o: ../../libraries/mathematics/factorization_methods.h ../../libraries/mathematics/factorization_methods.c
	gcc -c ../../libraries/mathematics/factorization_methods.c -o ../../libraries/mathematics/.factorization_methods.o

.factorizer.o: factorizer.c
	gcc -c factorizer.c -o .factorizer.o

factorizer: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.factorization_methods.o .factorizer.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.factorization_methods.o .factorizer.o -o ../../../WORKBENCH/factorizer
