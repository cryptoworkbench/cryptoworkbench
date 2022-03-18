../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

.plot_polynomial.o: plot_polynomial.c
	gcc -c plot_polynomial.c -o .plot_polynomial.o

plot_polynomial: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .plot_polynomial.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .plot_polynomial.o -o ../../../applications/plot_polynomial
