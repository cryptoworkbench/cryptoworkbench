../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/mathematics/.group_operations.o: ../../libraries/mathematics/group_operations.h ../../libraries/mathematics/group_operations.c
	gcc -c ../../libraries/mathematics/group_operations.c -o ../../libraries/mathematics/.group_operations.o

.group_examplifier.o: group_examplifier.c
	gcc -c group_examplifier.c -o .group_examplifier.o

group_examplifier: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_operations.o .group_examplifier.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_operations.o .group_examplifier.o -o ../../../tools/group_examplifier
