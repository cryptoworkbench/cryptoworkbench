../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.parabola_finite_field_plot.o: parabola_finite_field_plot.c
	gcc -c parabola_finite_field_plot.c -o .parabola_finite_field_plot.o

parabola_finite_field_plot: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .parabola_finite_field_plot.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .parabola_finite_field_plot.o -o ../../../WORKBENCH/parabola_finite_field_plot
