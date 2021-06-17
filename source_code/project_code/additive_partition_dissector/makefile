../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

.outline.o: outline.c
	gcc -c outline.c -o .outline.o

outline: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .outline.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o .outline.o -o ../../../tools/outline

.additive_partition_dissector.o: additive_partition_dissector.c
	gcc -c additive_partition_dissector.c -o .additive_partition_dissector.o

additive_partition_dissector: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .additive_partition_dissector.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o .additive_partition_dissector.o -o ../../../tools/additive_partition_dissector

.base_converter.o: base_converter.c
	gcc -c base_converter.c -o .base_converter.o

base_converter: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .base_converter.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o .base_converter.o -o ../../../tools/base_converter
