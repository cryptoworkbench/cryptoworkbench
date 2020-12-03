string.o: ../../../libraries/functional/string.h ../../../libraries/functional/string.c ../../../libraries/mathematics/maths.h ../../../libraries/mathematics/maths.c
	cd ../../../libraries/functional && make string.o

maximum_values.o: maximum_values.c
	gcc -c maximum_values.c -o maximum_values.o

maximum_values: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o maximum_values.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o maximum_values.o -o maximum_values
