../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.basic.o: ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	gcc -c ../../libraries/mathematics/math.basic.c -o ../../libraries/mathematics/.math.basic.o

../../libraries/mathematics/.math.extended.o: ../../libraries/mathematics/math.extended.h ../../libraries/mathematics/math.extended.c
	gcc -c ../../libraries/mathematics/math.extended.c -o ../../libraries/mathematics/.math.extended.o

.divide.o: divide.c
	gcc -c divide.c -o .divide.o

divide: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o .divide.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o .divide.o -o ../../../applications/divide
