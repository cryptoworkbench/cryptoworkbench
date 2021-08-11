../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.LOGBOOK_library.o: ../../libraries/functional/LOGBOOK_library.h ../../libraries/functional/LOGBOOK_library.c
	gcc -c ../../libraries/functional/LOGBOOK_library.c -o ../../libraries/functional/.LOGBOOK_library.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

.subgroup_examplifier.o: subgroup_examplifier.c
	gcc -c subgroup_examplifier.c -o .subgroup_examplifier.o

subgroup_examplifier: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o ../../libraries/functional/.triple_ref_pointers.o .subgroup_examplifier.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o ../../libraries/functional/.triple_ref_pointers.o .subgroup_examplifier.o -o ../../../WORKBENCH/subgroup_examplifier
