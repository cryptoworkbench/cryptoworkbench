../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.SIGNAL.o: ../../libraries/functional/SIGNAL.h ../../libraries/functional/SIGNAL.c
	gcc -c ../../libraries/functional/SIGNAL.c -o ../../libraries/functional/.SIGNAL.o

../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

.primes.o: primes.c
	gcc -c primes.c -o .primes.o

primes: ../../libraries/mathematics/.maths.o ../../libraries/functional/.SIGNAL.o ../../libraries/functional/.string.o .primes.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.SIGNAL.o ../../libraries/functional/.string.o .primes.o -o ../../../WORKBENCH/.primes
