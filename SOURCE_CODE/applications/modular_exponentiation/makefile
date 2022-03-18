../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math_extended.o: ../../libraries/mathematics/math_extended.h ../../libraries/mathematics/math_extended.c ../../libraries/mathematics/math_basic.h ../../libraries/mathematics/math_basic.c
	cd ../../libraries/mathematics && make math_extended_LIBRARY

.modular_exponentiation.o: modular_exponentiation.c
	gcc -c modular_exponentiation.c -o .modular_exponentiation.o

modular_exponentiation: ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .modular_exponentiation.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .modular_exponentiation.o -o ../../../applications/modular_exponentiation
