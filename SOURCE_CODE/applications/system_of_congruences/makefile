../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math_basic.o: ../../libraries/mathematics/math_basic.h ../../libraries/mathematics/math_basic.c
	gcc -c ../../libraries/mathematics/math_basic.c -o ../../libraries/mathematics/.math_basic.o

.system_of_congruences.o: system_of_congruences.c
	gcc -c system_of_congruences.c -o .system_of_congruences.o

system_of_congruences: ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o .system_of_congruences.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o .system_of_congruences.o -o ../../../applications/system_of_congruences
