../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/functional/.string.extended.o: ../../libraries/functional/string.extended.h ../../libraries/functional/string.extended.c
	gcc -c ../../libraries/functional/string.extended.c -o ../../libraries/functional/.string.extended.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

.greatest_common_divisor.o: greatest_common_divisor.c
	gcc -c greatest_common_divisor.c -o .greatest_common_divisor.o

greatest_common_divisor: ../../libraries/functional/.string.basic.o ../../libraries/functional/.string.extended.o ../../libraries/mathematics/.maths.basic.o .greatest_common_divisor.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/functional/.string.extended.o  ../../libraries/mathematics/.maths.basic.o .greatest_common_divisor.o -o ../../../applications/greatest_common_divisor
