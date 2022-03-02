../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.greatest_common_divisor.o: greatest_common_divisor.c
	gcc -c greatest_common_divisor.c -o .greatest_common_divisor.o

greatest_common_divisor: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .greatest_common_divisor.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .greatest_common_divisor.o -o ../../../applications/greatest_common_divisor
