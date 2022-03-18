../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.extended.o: ../../libraries/mathematics/math.extended.h ../../libraries/mathematics/math.extended.c ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	cd ../../libraries/mathematics && make math.extended_LIBRARY

.field_combine.o: field_combine.c
	gcc -c field_combine.c -o .field_combine.o

field_combine: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o .field_combine.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o .field_combine.o -o ../../../applications/field_combine
