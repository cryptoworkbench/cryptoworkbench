string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make string.o

.multiplicative_group_of_integers.o: multiplicative_group_of_integers.c
	gcc -c multiplicative_group_of_integers.c -o .multiplicative_group_of_integers.o

multiplicative_group_of_integers: ../../libraries/mathematics/maths.o ../../libraries/functional/string.o .multiplicative_group_of_integers.o
	gcc ../../libraries/mathematics/maths.o ../../libraries/functional/string.o .multiplicative_group_of_integers.o -o ../../../workbench/multiplicative_group_of_integers
