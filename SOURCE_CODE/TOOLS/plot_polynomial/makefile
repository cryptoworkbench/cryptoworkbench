../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.plot_polynomial.o: plot_polynomial.c
	gcc -c plot_polynomial.c -o .plot_polynomial.o

plot_polynomial: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .plot_polynomial.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .plot_polynomial.o -o ../../../TOOLS/plot_polynomial
