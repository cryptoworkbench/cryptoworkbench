string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

RSA.o: RSA.c
	gcc -c RSA.c -o RSA.o

RSA: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o RSA.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o RSA.o -o RSA && rm RSA.o
