../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math_extended.o: ../../libraries/mathematics/math_extended.h ../../libraries/mathematics/math_extended.c ../../libraries/mathematics/math_basic.h ../../libraries/mathematics/math_basic.c
	cd ../../libraries/mathematics && make math_extended_LIBRARY

.prime_table_exporter.o: prime_table_exporter.c
	gcc -c prime_table_exporter.c -o .prime_table_exporter.o

prime_table_exporter: ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .prime_table_exporter.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .prime_table_exporter.o -o ../../../applications/prime_table_exporter
