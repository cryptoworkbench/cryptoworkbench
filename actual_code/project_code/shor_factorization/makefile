string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

shor_factorization.o: shor_factorization.c
	gcc -c shor_factorization.c -o shor_factorization.o

shor_factorization: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o shor_factorization.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o shor_factorization.o -o shor_factorization && rm shor_factorization.o
