string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

additive_partition_dissector.o: additive_partition_dissector.c
	gcc -c additive_partition_dissector.c -o additive_partition_dissector.o

additive_partition_dissector: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o additive_partition_dissector.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o additive_partition_dissector.o -o additive_partition_dissector && rm additive_partition_dissector.o

base_converter.o: base_converter.c
	gcc -c base_converter.c -o base_converter.o

base_converter: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o base_converter.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o base_converter.o -o base_converter && rm base_converter.o
