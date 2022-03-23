../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

.sieve_of_eratosthenes.o: sieve_of_eratosthenes.c
	gcc -c sieve_of_eratosthenes.c -o .sieve_of_eratosthenes.o

sieve_of_eratosthenes: ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o .sieve_of_eratosthenes.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o .sieve_of_eratosthenes.o -o ../../../applications/sieve_of_eratosthenes
