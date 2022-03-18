../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.extended.o: ../../libraries/mathematics/math.extended.h ../../libraries/mathematics/math.extended.c ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	cd ../../libraries/mathematics && make math.extended_LIBRARY

.multiplicative_inverse.o: multiplicative_inverse.c
	gcc -c multiplicative_inverse.c -o .multiplicative_inverse.o

multiplicative_inverse: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o .multiplicative_inverse.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o .multiplicative_inverse.o -o ../../../applications/multiplicative_inverse
