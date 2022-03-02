../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.system_of_congruences.o: system_of_congruences.c
	gcc -c system_of_congruences.c -o .system_of_congruences.o

system_of_congruences: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .system_of_congruences.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .system_of_congruences.o -o ../../../TOOLS/system_of_congruences
