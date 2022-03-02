../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.random_numbers.o: random_numbers.c
	gcc -c random_numbers.c -o .random_numbers.o

random_numbers: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .random_numbers.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .random_numbers.o -o ../../../applications/random_numbers
