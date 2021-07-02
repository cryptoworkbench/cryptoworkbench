../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

.modular_exponentiation.o: modular_exponentiation.c
	gcc -c modular_exponentiation.c -o .modular_exponentiation.o

modular_exponentiation: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .modular_exponentiation.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o .modular_exponentiation.o -o ../../../crypto_lab/tools/modular_exponentiation
