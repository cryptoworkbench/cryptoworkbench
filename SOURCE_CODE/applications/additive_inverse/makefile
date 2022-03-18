../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

.additive_inverse.o: additive_inverse.c
	gcc -c additive_inverse.c -o .additive_inverse.o

additive_inverse: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .additive_inverse.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .additive_inverse.o -o ../../../applications/additive_inverse
