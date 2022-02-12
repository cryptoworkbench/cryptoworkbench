../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.factorization_methods.o: ../../libraries/mathematics/factorization_methods.h ../../libraries/mathematics/factorization_methods.c
	gcc -c ../../libraries/mathematics/factorization_methods.c -o ../../libraries/mathematics/.factorization_methods.o
	
../../libraries/mathematics/.primality_testing.o: ../../libraries/mathematics/primality_testing.h ../../libraries/mathematics/primality_testing.c
	gcc -c ../../libraries/mathematics/primality_testing.c -o ../../libraries/mathematics/.primality_testing.o

.legendre_symbol.o: legendre_symbol.c
	gcc -c legendre_symbol.c -o .legendre_symbol.o

legendre_symbol: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.factorization_methods.o ../../libraries/mathematics/.primality_testing.o .legendre_symbol.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.factorization_methods.o ../../libraries/mathematics/.primality_testing.o .legendre_symbol.o -o ../../../WORKBENCH/legendre_symbol
