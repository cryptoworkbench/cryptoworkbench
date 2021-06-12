string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make string.o

.multiplicative_group_generator.o: multiplicative_group_generator.c
	gcc -c multiplicative_group_generator.c -o .multiplicative_group_generator.o

multiplicative_group_generator: ../../libraries/mathematics/maths.o ../../libraries/functional/string.o .multiplicative_group_generator.o
	gcc ../../libraries/mathematics/maths.o ../../libraries/functional/string.o .multiplicative_group_generator.o -o ../../../workbench/multiplicative_group_generator
