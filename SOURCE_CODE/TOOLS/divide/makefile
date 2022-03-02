../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.divide.o: divide.c
	gcc -c divide.c -o .divide.o

divide: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .divide.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .divide.o -o ../../../TOOLS/divide
