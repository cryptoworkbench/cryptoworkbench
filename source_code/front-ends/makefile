../libraries/functional/.string.o: ../libraries/mathematics/maths.c ../libraries/mathematics/maths.h ../libraries/functional/string.c ../libraries/functional/string.h
	cd ../libraries/functional && make .string.o

../libraries/functional/.triple_ref_pointers.o: ../libraries/functional/triple_ref_pointers.h ../libraries/functional/triple_ref_pointers.c
	gcc -c ../libraries/functional/triple_ref_pointers.c -o ../libraries/functional/.triple_ref_pointers.o

../libraries/mathematics/.factorization_engines.o: ../libraries/mathematics/factorization_engines.h ../libraries/mathematics/factorization_engines.c
	gcc -c ../libraries/mathematics/factorization_engines.c -o ../libraries/mathematics/.factorization_engines.o

.multiplicative_partition_dissection.o: multiplicative_partition_dissection.c
	gcc -c multiplicative_partition_dissection.c -o .multiplicative_partition_dissection.o

multiplicative_partition_dissection: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o ../libraries/mathematics/.factorization_engines.o .multiplicative_partition_dissection.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o ../libraries/mathematics/.factorization_engines.o .multiplicative_partition_dissection.o -o ../../crypto_lab/tools/multiplicative_partition_dissection

.euclidean_algorithm.o: euclidean_algorithm.c
	gcc -c euclidean_algorithm.c -o .euclidean_algorithm.o

euclidean_algorithm: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o ../libraries/functional/.triple_ref_pointers.o .euclidean_algorithm.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o ../libraries/functional/.triple_ref_pointers.o .euclidean_algorithm.o -o ../../crypto_lab/tools//euclidean_algorithm

.primality_checker.o: primality_checker.c
	gcc -c primality_checker.c -o .primality_checker.o

primality_checker: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o .primality_checker.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o .primality_checker.o -o ../../crypto_lab/tools/primality_checker

.lookup_factorize.o: lookup_factorize.c
	gcc -c lookup_factorize.c -o .lookup_factorize.o

lookup_factorize: ../libraries/functional/.string.o ../libraries/mathematics/.maths.o .lookup_factorize.o
	gcc ../libraries/mathematics/.maths.o ../libraries/functional/.string.o .lookup_factorize.o -o ../../crypto_lab/tools/lookup_factorize
