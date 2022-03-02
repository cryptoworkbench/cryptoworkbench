../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.equivalence_class.o: equivalence_class.c
	gcc -c equivalence_class.c -o .equivalence_class.o

equivalence_class: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .equivalence_class.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .equivalence_class.o -o ../../../applications/equivalence_class
