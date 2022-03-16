../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.equivalence_class_members.o: equivalence_class_members.c
	gcc -c equivalence_class_members.c -o .equivalence_class_members.o

equivalence_class_members: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .equivalence_class_members.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .equivalence_class_members.o -o ../../../applications/equivalence_class_members
