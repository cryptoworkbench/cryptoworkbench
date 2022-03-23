../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

.random_numbers.o: random_numbers.c
	gcc -c random_numbers.c -o .random_numbers.o

random_numbers: ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o .random_numbers.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o .random_numbers.o -o ../../../applications/random_numbers
