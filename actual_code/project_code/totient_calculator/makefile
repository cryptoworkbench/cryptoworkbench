string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

totient_calculator.o: totient_calculator.c
	gcc -c totient_calculator.c -o totient_calculator.o

totient_calculator: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o totient_calculator.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o totient_calculator.o -o totient_calculator
	rm totient_calculator.o
