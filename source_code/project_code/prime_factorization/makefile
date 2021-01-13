../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

.prime_factorization.o: prime_factorization.c
	gcc -c prime_factorization.c -o .prime_factorization.o

prime_factorization: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o  .prime_factorization.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.triple_ref_pointers.o .prime_factorization.o -o ../../../workbench/prime_factorization
	echo "APPLICATION 'prime_factorization' is now ready in /workbench/"
