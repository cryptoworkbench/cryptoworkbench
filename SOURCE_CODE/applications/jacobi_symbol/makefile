../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.extended.o: ../../libraries/mathematics/math.extended.h ../../libraries/mathematics/math.extended.c ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	cd ../../libraries/mathematics && make math.extended_LIBRARY

../../libraries/mathematics/.factorization_methods.o: ../../libraries/mathematics/factorization_methods.h ../../libraries/mathematics/factorization_methods.c
	gcc -c ../../libraries/mathematics/factorization_methods.c -o ../../libraries/mathematics/.factorization_methods.o
	
.jacobi_symbol.o: jacobi_symbol.c
	gcc -c jacobi_symbol.c -o .jacobi_symbol.o

jacobi_symbol: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o ../../libraries/mathematics/.factorization_methods.o .jacobi_symbol.o .jacobi_symbol.sh
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o ../../libraries/mathematics/.factorization_methods.o .jacobi_symbol.o -o ../../../applications/jacobi_symbol && cp .jacobi_symbol.sh ../../../applications/jacobi_symbol.sh
