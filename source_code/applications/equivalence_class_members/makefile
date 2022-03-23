../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

.equivalence_class_members.o: equivalence_class_members.c
	gcc -c equivalence_class_members.c -o .equivalence_class_members.o

equivalence_class_members: ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.extended.o .equivalence_class_members.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.extended.o .equivalence_class_members.o -o ../../../applications/equivalence_class_members
