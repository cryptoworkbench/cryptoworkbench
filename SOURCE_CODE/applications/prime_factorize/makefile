../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.basic.o: ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	gcc -c ../../libraries/mathematics/math.basic.c -o ../../libraries/mathematics/.math.basic.o

../../libraries/mathematics/.math.extended.o: ../../libraries/mathematics/math.extended.h ../../libraries/mathematics/math.extended.c
	gcc -c ../../libraries/mathematics/math.extended.c -o ../../libraries/mathematics/.math.extended.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/mathematics/.factorization_methods.o: ../../libraries/mathematics/factorization_methods.h ../../libraries/mathematics/factorization_methods.c
	gcc -c ../../libraries/mathematics/factorization_methods.c -o ../../libraries/mathematics/.factorization_methods.o

.prime_factorize.o: prime_factorize.c
	gcc -c prime_factorize.c -o .prime_factorize.o

prime_factorize: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.factorization_methods.o .prime_factorize.o
	gcc -c ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.factorization_methods.o .prime_factorize.o -o ../../../applications/prime_factorize
