string.o: ../../../libraries/mathematics/maths.h ../../../libraries/mathematics/maths.c ../../../libraries/functional/string.h ../../../libraries/functional/string.c
	cd ../../../libraries/functional/ && make string.o

most_naive_primality_test.o: most_naive_primality_test.c
	gcc -c most_naive_primality_test.c -o most_naive_primality_test.o

most_naive_primality_test: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o most_naive_primality_test.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o most_naive_primality_test.o -o most_naive_primality_test
