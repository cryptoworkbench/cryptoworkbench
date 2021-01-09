string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

partition_dissector.o: partition_dissector.c
	gcc -c partition_dissector.c -o partition_dissector.o

partition_dissector: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o partition_dissector.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o partition_dissector.o -o partition_dissector && rm partition_dissector.o

base_converter.o: base_converter.c
	gcc -c base_converter.c -o base_converter.o

base_converter: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o base_converter.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o base_converter.o -o base_converter && rm base_converter.o
