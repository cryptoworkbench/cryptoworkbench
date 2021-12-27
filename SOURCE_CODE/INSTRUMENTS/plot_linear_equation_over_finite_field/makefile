../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.plot_linear_equation_over_finite_field.o: plot_linear_equation_over_finite_field.c
	gcc -c plot_linear_equation_over_finite_field.c -o .plot_linear_equation_over_finite_field.o

plot_linear_equation_over_finite_field: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .plot_linear_equation_over_finite_field.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .plot_linear_equation_over_finite_field.o -o ../../../WORKBENCH/plot_linear_equation_over_finite_field
