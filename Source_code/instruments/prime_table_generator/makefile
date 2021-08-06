../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c 
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.prime_table_generator.o: prime_table_generator.c
	gcc -c prime_table_generator.c -o .prime_table_generator.o

prime_table_generator:../../libraries/functional/.string.o  ../../libraries/mathematics/.maths.o .prime_table_generator.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .prime_table_generator.o -o ../../../crypto_lab/instruments/prime_table_generator
