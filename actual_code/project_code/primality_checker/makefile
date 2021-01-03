string.o: ../../../libraries/mathematics/maths.h ../../../libraries/mathematics/maths.c ../../../libraries/functional/string.h ../../../libraries/functional/string.c
	cd ../../../libraries/functional/ && make string.o

primality_checker.o: primality_checker.c
	gcc -c primality_checker.c -o primality_checker.o

primality_checker: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o primality_checker.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o primality_checker.o -o primality_checker && rm primality_checker.o
