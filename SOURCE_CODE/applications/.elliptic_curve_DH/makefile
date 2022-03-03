../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.elliptic_curve_DH.o: elliptic_curve_DH.c
	gcc -c elliptic_curve_DH.c -o .elliptic_curve_DH.o

elliptic_curve_DH: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .elliptic_curve_DH.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .elliptic_curve_DH.o -o elliptic_curve_DH
