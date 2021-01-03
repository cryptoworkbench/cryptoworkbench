string.o: ../../../../libraries/mathematics/maths.c ../../../../libraries/mathematics/maths.h ../../../../libraries/functional/string.c ../../../../libraries/functional/string.h
	cd ../../../../libraries/functional && make string.o

fermats_algorithm.o: ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.c ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.h
	gcc -c ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.c -o ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.o


frontend_one.o: frontend_one.c
	gcc -c frontend_one.c -o frontend_one.o

frontend_two.o: frontend_two.c
	gcc -c frontend_two.c -o frontend_two.o

frontend_one: ../../../../libraries/mathematics/maths.o ../../../../libraries/functional/string.o ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.o frontend_one.o
	gcc ../../../../libraries/mathematics/maths.o ../../../../libraries/functional/string.o ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.o frontend_one.o -o frontend_one && rm frontend_one.o && rm ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.o

frontend_two: ../../../../libraries/mathematics/maths.o ../../../../libraries/functional/string.o ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.o frontend_two.o
	gcc ../../../../libraries/mathematics/maths.o ../../../../libraries/functional/string.o ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.o frontend_two.o -o frontend_two && rm frontend_two.o && rm ../../../../libraries/mathematics/factorization_engines/fermats_algorithm.o
