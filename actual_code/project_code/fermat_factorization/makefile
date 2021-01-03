string.o: ../../../libraries/mathematics/maths.c ../../../libraries/functional/string.h ../../../libraries/functional/string.c
	cd ../../../libraries/functional && make string.o

fermat_factorization.o: fermat_factorization.c
	gcc -c fermat_factorization.c -o fermat_factorization.o
	
fermat_factorization: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o fermat_factorization.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o fermat_factorization.o -o fermat_factorization && rm fermat_factorization.o

exquisite_fermat_factorization.o: exquisite_fermat_factorization.c
	gcc -c exquisite_fermat_factorization.c -o exquisite_fermat_factorization.o

exquisite_fermat_factorization: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o exquisite_fermat_factorization.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o exquisite_fermat_factorization.o -o exquisite_fermat_factorization && rm exquisite_fermat_factorization.o
