../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/functional/.logbook_functions.o: ../../libraries/functional/logbook_functions.h ../../libraries/functional/logbook_functions.c
	gcc -c ../../libraries/functional/logbook_functions.c -o ../../libraries/functional/.logbook_functions.o

../../libraries/functional/.registry_functions.o: ../../libraries/functional/registry_functions.h ../../libraries/functional/registry_functions.c
	gcc -c ../../libraries/functional/registry_functions.c -o ../../libraries/functional/.registry_functions.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/mathematics/.group_operations.o: ../../libraries/mathematics/group_operations.h ../../libraries/mathematics/group_operations.c
	gcc -c ../../libraries/mathematics/group_operations.c -o ../../libraries/mathematics/.group_operations.o

.subgroup_examplifier.o: subgroup_examplifier.c
	gcc -c subgroup_examplifier.c -o .subgroup_examplifier.o

subgroup_examplifier: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.registry_functions.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_operations.o .subgroup_examplifier.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.registry_functions.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_operations.o .subgroup_examplifier.o -o ../../../toolbox/subgroup_examplifier
