../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.primality_testing.o: ../../libraries/mathematics/primality_testing.h ../../libraries/mathematics/primality_testing.c
	gcc -c ../../libraries/mathematics/primality_testing.c -o ../../libraries/mathematics/.primality_testing.o

../../libraries/mathematics/.factorization_methods.o: ../../libraries/mathematics/factorization_methods.h ../../libraries/mathematics/factorization_methods.c
	gcc -c ../../libraries/mathematics/factorization_methods.c -o ../../libraries/mathematics/.factorization_methods.o

.prime_factorize.o: prime_factorize.c
	gcc -c prime_factorize.c -o .prime_factorize.o

prime_factorize: ../../libraries/functional/.string.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.maths.o  ../../libraries/mathematics/.primality_testing.o ../../libraries/mathematics/.factorization_methods.o .prime_factorize.o
	gcc ../../libraries/functional/.string.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.maths.o  ../../libraries/mathematics/.primality_testing.o ../../libraries/mathematics/.factorization_methods.o .prime_factorize.o -o ../../../WORKBENCH/prime_factorize
