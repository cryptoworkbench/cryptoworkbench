string.o: ../../../../libraries/mathematics/maths.c ../../../../libraries/mathematics/maths.h ../../../../libraries/functional/string.c ../../../../libraries/functional/string.h
	cd ../../../../libraries/functional && make string.o

maths_verbose.o: ../../../../libraries/mathematics/maths_verbose.c ../../../../libraries/mathematics/maths_verbose.h
	gcc -c ../../../../libraries/mathematics/maths_verbose.c -o ../../../../libraries/mathematics/maths_verbose.o

gcd_calculator.o: gcd_calculator.c
	gcc -c gcd_calculator.c -o gcd_calculator.o

gcd_calculator: ../../../../libraries/mathematics/maths.o ../../../../libraries/functional/string.o ../../../../libraries/mathematics/maths_verbose.o gcd_calculator.o
	gcc ../../../../libraries/mathematics/maths.o ../../../../libraries/functional/string.o ../../../../libraries/mathematics/maths_verbose.o gcd_calculator.o -o gcd_calculator
