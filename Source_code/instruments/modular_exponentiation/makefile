../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.modular_exponentiation.o: modular_exponentiation.c
	gcc -c modular_exponentiation.c -o .modular_exponentiation.o

modular_exponentiation: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .modular_exponentiation.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .modular_exponentiation.o -o ../../../crypto_lab/instruments/modular_exponentiation
