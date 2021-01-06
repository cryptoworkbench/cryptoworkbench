string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make string.o

fermat_factorization.o: ../../libraries/mathematics/factorization_engines/fermat_factorization/fermat_factorization.c ../../libraries/mathematics/factorization_engines/fermat_factorization/fermat_factorization.h
	gcc -c ../../libraries/mathematics/factorization_engines/fermat_factorization/fermat_factorization.c -o ../../libraries/mathematics/factorization_engines/fermat_factorization/fermat_factorization.o

classic_shor.o: ../../libraries/mathematics/factorization_engines/classic_shor/classic_shor.c
	gcc -c ../../libraries/mathematics/factorization_engines/classic_shor/classic_shor.c -o ../../libraries/mathematics/factorization_engines/classic_shor/classic_shor.o



factorization.o: factorization.c
	gcc -c factorization.c -o factorization.o

sactorization.o: sactorization.c
	gcc -c sactorization.c -o sactorization.o



sactorization: ../../libraries/mathematics/maths.o ../../libraries/functional/string.o ../../libraries/mathematics/factorization_engines/classic_shor/classic_shor.o sactorization.o
	gcc ../../libraries/mathematics/maths.o ../../libraries/functional/string.o ../../libraries/mathematics/factorization_engines/classic_shor/classic_shor.o sactorization.o -o sactorization && rm sactorization.o

factorization: ../../libraries/mathematics/maths.o ../../libraries/functional/string.o ../../libraries/mathematics/factorization_engines/fermat_factorization/fermat_factorization.o ../../libraries/mathematics/factorization_engines/classic_shor/classic_shor.o factorization.o
	gcc ../../libraries/mathematics/maths.o ../../libraries/functional/string.o ../../libraries/mathematics/factorization_engines/fermat_factorization/fermat_factorization.o ../../libraries/mathematics/factorization_engines/classic_shor/classic_shor.o factorization.o -o factorization && rm factorization.o && rm ../../libraries/mathematics/factorization_engines/fermat_factorization/fermat_factorization.o ../../libraries/mathematics/factorization_engines/classic_shor/classic_shor.o
