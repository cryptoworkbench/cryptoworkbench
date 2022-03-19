../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

../../libraries/mathematics/.factorization_methods.o: ../../libraries/mathematics/factorization_methods.h ../../libraries/mathematics/factorization_methods.c
	gcc -c ../../libraries/mathematics/factorization_methods.c -o ../../libraries/mathematics/.factorization_methods.o

.factorize.o: factorize.c
	gcc -c factorize.c -o .factorize.o

factorize: ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/mathematics/.factorization_methods.o .factorize.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/mathematics/.factorization_methods.o .factorize.o -o ../../../applications/factorize
