../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/mathematics/.maths.groups.o: ../../libraries/mathematics/maths.groups.h ../../libraries/mathematics/maths.groups.c
	gcc -c ../../libraries/mathematics/maths.groups.c -o ../../libraries/mathematics/.maths.groups.o

.group_examplifier.o: group_examplifier.c
	gcc -c group_examplifier.c -o .group_examplifier.o

group_examplifier: ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.maths.groups.o .group_examplifier.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.maths.groups.o .group_examplifier.o -o ../../../applications/group_examplifier
