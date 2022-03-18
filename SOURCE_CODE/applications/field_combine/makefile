../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

.field_combine.o: field_combine.c
	gcc -c field_combine.c -o .field_combine.o

field_combine: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .field_combine.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .field_combine.o -o ../../../applications/field_combine
