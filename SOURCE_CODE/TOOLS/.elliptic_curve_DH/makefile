../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

.elliptic_curve_DH.o: elliptic_curve_DH.c
	gcc -c elliptic_curve_DH.c -o .elliptic_curve_DH.o

elliptic_curve_DH: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .elliptic_curve_DH.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .elliptic_curve_DH.o -o elliptic_curve_DH
