string.o: ../../../libraries/mathematics/maths.h ../../../libraries/mathematics/maths.c ../../../libraries/functional/string.h ../../../libraries/functional/string.c
	cd ../../../libraries/functional/ && make string.o

prime_table_generator.o: prime_table_generator.c
	gcc -c prime_table_generator.c -o prime_table_generator.o

prime_table_generator: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o prime_table_generator.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o prime_table_generator.o -o prime_table_generator

prime_table_reader.o: prime_table_reader.c
	gcc -c prime_table_reader.c -o prime_table_reader.o

prime_table_reader: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o prime_table_reader.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o prime_table_reader.o -o prime_table_reader
