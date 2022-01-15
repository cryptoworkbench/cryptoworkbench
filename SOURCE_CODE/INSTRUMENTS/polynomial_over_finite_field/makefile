../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.polynomials_over_finite_fields.o: polynomials_over_finite_fields.c
	gcc -c polynomials_over_finite_fields.c -o .polynomials_over_finite_fields.o

polynomials_over_finite_fields: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .polynomials_over_finite_fields.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .polynomials_over_finite_fields.o -o polynomials_over_finite_fields
