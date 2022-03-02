../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.prime_table_exporter.o: prime_table_exporter.c
	gcc -c prime_table_exporter.c -o .prime_table_exporter.o

prime_table_exporter: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .prime_table_exporter.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .prime_table_exporter.o -o ../../../applications/prime_table_exporter
