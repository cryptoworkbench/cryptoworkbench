string.o: ../../../libraries/functional/string.h ../../../libraries/functional/string.c
	cd ../../../libraries/functional && make string.o

factor_set_intersection.o: factor_set_intersection.c
	gcc -c factor_set_intersection.c -o factor_set_intersection.o

factor_set_intersection: ../../../libraries/functional/string.o ../../../libraries/mathematics/maths.o factor_set_intersection.o
	gcc ../../../libraries/functional/string.o ../../../libraries/mathematics/maths.o factor_set_intersection.o -o factor_set_intersection && rm factor_set_intersection.o
