string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

partition_dissector.o: partition_dissector.c
	gcc -c partition_dissector.c -o partition_dissector.o

partition_dissector: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o partition_dissector.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o partition_dissector.o -o partition_dissector && rm partition_dissector.o
