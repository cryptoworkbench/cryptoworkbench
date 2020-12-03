string.o: ../../../libraries/mathematics/maths.h  ../../../libraries/mathematics/maths.c ../../../libraries/functional/string.h ../../../libraries/functional/string.c
	cd ../../../libraries/functional && make string.o

multiplicative_inverse.o: multiplicative_inverse.c
	gcc -c multiplicative_inverse.c -o multiplicative_inverse.o

multiplicative_inverse: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o multiplicative_inverse.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o multiplicative_inverse.o -o multiplicative_inverse && rm multiplicative_inverse.o
