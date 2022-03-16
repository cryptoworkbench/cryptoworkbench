../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.modulus_operation.o: modulus_operation.c
	gcc -c modulus_operation.c -o .modulus_operation.o

modulus_operation: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .modulus_operation.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .modulus_operation.o -o ../../../applications/modulus_operation
