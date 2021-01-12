../libraries/functional/.string.o: ../libraries/mathematics/maths.c ../libraries/mathematics/maths.h ../libraries/functional/string.c ../libraries/functional/string.h
	cd ../libraries/functional && make .string.o

../libraries/functional/.triple_ref_pointers.o: ../libraries/functional/triple_ref_pointers.h ../libraries/functional/triple_ref_pointers.c
	gcc -c ../libraries/functional/triple_ref_pointers.c -o ../libraries/functional/.triple_ref_pointers.o

../libraries/mathematics/.factorization_engines.o: ../libraries/mathematics/factorization_engines.h ../libraries/mathematics/factorization_engines.c
	gcc -c ../libraries/mathematics/factorization_engines.c -o ../libraries/mathematics/.factorization_engines.o

.multiplicative_partition_dissection.o: multiplicative_partition_dissection.c
	gcc -c multiplicative_partition_dissection.c -o .multiplicative_partition_dissection.o

multiplicative_partition_dissection: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o ../libraries/mathematics/.factorization_engines.o .multiplicative_partition_dissection.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o ../libraries/mathematics/.factorization_engines.o .multiplicative_partition_dissection.o -o ../../workbench/multiplicative_partition_dissection
	echo "APPLICATION 'multiplicative_partition_dissection' is now ready in /workbench/"

.euclidean_algorithm.o: euclidean_algorithm.c
	gcc -c euclidean_algorithm.c -o .euclidean_algorithm.o

euclidean_algorithm: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o ../libraries/functional/.triple_ref_pointers.o .euclidean_algorithm.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o ../libraries/functional/.triple_ref_pointers.o .euclidean_algorithm.o -o ../../workbench/euclidean_algorithm
	echo "APPLICATION 'euclidean_algorithm' is now ready in /workbench/"

.primality_checker.o: primality_checker.c
	gcc -c primality_checker.c -o .primality_checker.o

primality_checker: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o .primality_checker.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o .primality_checker.o -o ../../workbench/primality_checker
	echo "APPLICATION 'primality_checker' is now ready in /workbench/"

.lookup_factorize.o: lookup_factorize.c
	gcc -c lookup_factorize.c -o .lookup_factorize.o

lookup_factorize: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o .lookup_factorize.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o .lookup_factorize.o -o ../../workbench/lookup_factorize
	echo "APPLICATION 'lookup_factorize' is now ready in /workbench/"

.modular_exponentiation.o: modular_exponentiation.c
	gcc -c modular_exponentiation.c -o .modular_exponentiation.o

modular_exponentiation: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o .modular_exponentiation.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o .modular_exponentiation.o -o ../../workbench/modular_exponentiation
	echo "APPLICATION 'modular_exponentiation' is now ready in /workbench/"
