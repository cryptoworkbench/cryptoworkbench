string.o: ../../../../libraries/mathematics/maths.c ../../../../libraries/mathematics/maths.h ../../../../libraries/functional/string.c ../../../../libraries/functional/string.h
	cd ../../../../libraries/functional && make string.o

modular_exponentiation.o: modular_exponentiation.c
	gcc -c modular_exponentiation.c -o modular_exponentiation.o

modular_exponentiation: ../../../../libraries/mathematics/maths.o ../../../../libraries/functional/string.o modular_exponentiation.o
	gcc ../../../../libraries/mathematics/maths.o ../../../../libraries/functional/string.o modular_exponentiation.o -o modular_exponentiation
	rm modular_exponentiation.o
