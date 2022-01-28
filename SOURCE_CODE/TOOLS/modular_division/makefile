../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.modular_division.o: modular_division.c
	gcc -c modular_division.c -o .modular_division.o

modular_division: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .modular_division.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .modular_division.o -o ../../../WORKBENCH/modular_division
