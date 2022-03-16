../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.mod.o: mod.c
	gcc -c mod.c -o .mod.o

mod: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .mod.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .mod.o -o ../../../applications/mod
