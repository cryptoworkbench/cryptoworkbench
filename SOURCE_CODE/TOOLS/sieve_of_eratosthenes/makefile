../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.sieve_of_eratosthenes.o: sieve_of_eratosthenes.c
	gcc -c sieve_of_eratosthenes.c -o .sieve_of_eratosthenes.o

sieve_of_eratosthenes: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .sieve_of_eratosthenes.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .sieve_of_eratosthenes.o -o ../../../WORKBENCH/sieve_of_eratosthenes
