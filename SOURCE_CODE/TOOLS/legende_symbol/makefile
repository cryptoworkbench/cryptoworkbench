../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.factorization_methods.o: ../../libraries/mathematics/factorization_methods.h ../../libraries/mathematics/factorization_methods.c
	gcc -c ../../libraries/mathematics/factorization_methods.c -o ../../libraries/mathematics/.factorization_methods.o
	
../../libraries/mathematics/.primality_testing_scemes.o: ../../libraries/mathematics/primality_testing_scemes.h ../../libraries/mathematics/primality_testing_scemes.c
	gcc -c ../../libraries/mathematics/primality_testing_scemes.c -o ../../libraries/mathematics/.primality_testing_scemes.o

.legende_symbol.o: legende_symbol.c
	gcc -c legende_symbol.c -o .legende_symbol.o

legende_symbol: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.factorization_methods.o ../../libraries/mathematics/.primality_testing_scemes.o .legende_symbol.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.factorization_methods.o ../../libraries/mathematics/.primality_testing_scemes.o .legende_symbol.o -o ../../../WORKBENCH/legende_symbol
