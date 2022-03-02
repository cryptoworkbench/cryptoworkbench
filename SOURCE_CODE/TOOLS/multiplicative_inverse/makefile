../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.multiplicative_inverse.o: multiplicative_inverse.c
	gcc -c multiplicative_inverse.c -o .multiplicative_inverse.o

multiplicative_inverse: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .multiplicative_inverse.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .multiplicative_inverse.o -o ../../../TOOLS/multiplicative_inverse
