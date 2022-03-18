../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.basic.o: ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	gcc -c ../../libraries/mathematics/math.basic.c -o ../../libraries/mathematics/.math.basic.o

.random_numbers.o: random_numbers.c
	gcc -c random_numbers.c -o .random_numbers.o

random_numbers: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o .random_numbers.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o .random_numbers.o -o ../../../applications/random_numbers
