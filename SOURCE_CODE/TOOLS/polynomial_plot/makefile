../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.polynomial_plot.o: polynomial_plot.c
	gcc -c polynomial_plot.c -o .polynomial_plot.o

polynomial_plot: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .polynomial_plot.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .polynomial_plot.o -o ../../../WORKBENCH/polynomial_plot
