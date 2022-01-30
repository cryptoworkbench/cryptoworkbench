../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.additive_inverse.o: additive_inverse.c
	gcc -c additive_inverse.c -o .additive_inverse.o

additive_inverse: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .additive_inverse.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .additive_inverse.o -o ../../../WORKBENCH/additive_inverse
