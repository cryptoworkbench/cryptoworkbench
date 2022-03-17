../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.field_combine.o: field_combine.c
	gcc -c field_combine.c -o .field_combine.o

field_combine: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .field_combine.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .field_combine.o -o ../../../applications/field_combine
