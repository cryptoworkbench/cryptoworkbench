../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

.divide.o: divide.c
	gcc -c divide.c -o .divide.o

divide: ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .divide.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .divide.o -o ../../../applications/divide
