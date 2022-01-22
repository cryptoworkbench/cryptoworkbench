../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.factorization_methods.o: ../../libraries/mathematics/factorization_methods.h ../../libraries/mathematics/factorization_methods.c
	gcc -c ../../libraries/mathematics/factorization_methods.c -o ../../libraries/mathematics/.factorization_methods.o

../../libraries/mathematics/.universal_group_library.o: ../../libraries/mathematics/universal_group_library.h ../../libraries/mathematics/universal_group_library.c
	gcc -c ../../libraries/mathematics/universal_group_library.c -o ../../libraries/mathematics/.universal_group_library.o

.factorize.o: factorize.c
	gcc -c factorize.c -o .factorize.o

factorize: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.factorization_methods.o ../../libraries/mathematics/.universal_group_library.o .factorize.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.factorization_methods.o ../../libraries/mathematics/.universal_group_library.o .factorize.o -o ../../../WORKBENCH/factorize
