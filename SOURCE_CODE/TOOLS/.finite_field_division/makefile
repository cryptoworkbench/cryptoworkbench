../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.finite_field_division.o: finite_field_division.c
	gcc -c finite_field_division.c -o .finite_field_division.o

finite_field_division: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .finite_field_division.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .finite_field_division.o -o ../../../WORKBENCH/finite_field_division
