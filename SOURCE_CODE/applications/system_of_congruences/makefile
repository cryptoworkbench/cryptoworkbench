../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math_extended.o: ../../libraries/mathematics/math_extended.h ../../libraries/mathematics/math_extended.c ../../libraries/mathematics/math_basic.h ../../libraries/mathematics/math_basic.c
	cd ../../libraries/mathematics && make math_extended_LIBRARY

.system_of_congruences.o: system_of_congruences.c
	gcc -c system_of_congruences.c -o .system_of_congruences.o

system_of_congruences: ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .system_of_congruences.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .system_of_congruences.o -o ../../../applications/system_of_congruences
