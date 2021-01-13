../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

.prime_factorization.o: prime_factorization.c
	gcc -c prime_factorization.c -o .prime_factorization.o

prime_factorization: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o  .prime_factorization.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.triple_ref_pointers.o .prime_factorization.o -o ../../../workbench/prime_factorization
	echo "APPLICATION 'prime_factorization' is now ready in /workbench/"

.nicer.o: nicer.c
	gcc -c nicer.c -o .nicer.o

nicer: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o  .nicer.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.triple_ref_pointers.o .nicer.o -o ../../../workbench/nicer
	echo "APPLICATION 'nicer' is now ready in /workbench/"
