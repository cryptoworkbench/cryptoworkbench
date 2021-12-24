../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/mathematics/.universal_group_library.o: ../../libraries/mathematics/universal_group_library.h ../../libraries/mathematics/universal_group_library.c
	gcc -c ../../libraries/mathematics/universal_group_library.c -o ../../libraries/mathematics/.universal_group_library.o

.subgroup_information.o: subgroup_information.c
	gcc -c subgroup_information.c -o .subgroup_information.o

subgroup_information: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.universal_group_library.o .subgroup_information.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.universal_group_library.o .subgroup_information.o -o ../../../WORKBENCH/subgroup_information
