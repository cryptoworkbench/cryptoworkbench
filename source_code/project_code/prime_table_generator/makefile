../../libraries/functional/.string.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c ../../libraries/functional/string.h ../../libraries/functional/string.c
	cd ../../libraries/functional/ && make .string.o

.prime_table_generator.o: prime_table_generator.c
	gcc -c prime_table_generator.c -o .prime_table_generator.o

prime_table_generator:../../libraries/functional/.string.o  ../../libraries/mathematics/.maths.o .prime_table_generator.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o .prime_table_generator.o -o ../../../workbench/prime_table_generator
