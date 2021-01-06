string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make string.o

fermat_factorization.o: ../../libraries/mathematics/factorization_engines.h ../../libraries/mathematics/factorization_engines.c
	gcc -c ../../libraries/mathematics/factorization_engines.c -o ../../libraries/mathematics/factorization_engines.o


factorization.o: factorization.c
	gcc -c factorization.c -o factorization.o

factorization: ../../libraries/mathematics/maths.o ../../libraries/functional/string.o ../../libraries/mathematics/factorization_engines.o factorization.o
	gcc ../../libraries/mathematics/maths.o ../../libraries/functional/string.o ../../libraries/mathematics/factorization_engines.o factorization.o -o factorization && rm factorization.o
