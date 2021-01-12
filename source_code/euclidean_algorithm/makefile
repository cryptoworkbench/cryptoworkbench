../libraries/functional/.string.o: ../libraries/mathematics/maths.c ../libraries/mathematics/maths.h ../libraries/functional/string.c ../libraries/functional/string.h
	cd ../libraries/functional && make .string.o

.linked_lists.o: linked_lists.h linked_lists.c
	gcc -c linked_lists.c -o .linked_lists.o

.euclidean_algorithm.o: euclidean_algorithm.c
	gcc -c euclidean_algorithm.c -o .euclidean_algorithm.o

euclidean_algorithm: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o .linked_lists.o .euclidean_algorithm.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o .linked_lists.o .euclidean_algorithm.o -o ../../workbench/euclidean_algorithm
	echo "APPLICATION 'euclidean_algorithm' is now ready in /workbench/"

