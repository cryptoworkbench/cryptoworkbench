string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

additive_partitions.o: additive_partitions.c
	gcc -c additive_partitions.c -o additive_partitions.o

additive_partitions: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o additive_partitions.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o additive_partitions.o -o additive_partitions && rm additive_partitions.o
