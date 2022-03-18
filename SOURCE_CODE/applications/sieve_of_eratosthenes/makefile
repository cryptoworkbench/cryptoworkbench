../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.basic.o: ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	gcc -c ../../libraries/mathematics/math.basic.c -o ../../libraries/mathematics/.math.basic.o

.sieve_of_eratosthenes.o: sieve_of_eratosthenes.c
	gcc -c sieve_of_eratosthenes.c -o .sieve_of_eratosthenes.o

sieve_of_eratosthenes: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o .sieve_of_eratosthenes.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o .sieve_of_eratosthenes.o -o ../../../applications/sieve_of_eratosthenes
