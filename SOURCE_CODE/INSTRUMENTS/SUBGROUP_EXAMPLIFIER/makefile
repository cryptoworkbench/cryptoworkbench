../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/mathematics/.universal_group_library.o: ../../libraries/mathematics/universal_group_library.h ../../libraries/mathematics/universal_group_library.c
	gcc -c ../../libraries/mathematics/universal_group_library.c -o ../../libraries/mathematics/.universal_group_library.o

.error_functions.o: error_functions.h error_functions.c
	gcc -c error_functions.c -o .error_functions.o

.SUBGROUP_EXAMPLIFIER.o: SUBGROUP_EXAMPLIFIER.c
	gcc -c SUBGROUP_EXAMPLIFIER.c -o .SUBGROUP_EXAMPLIFIER.o

SUBGROUP_EXAMPLIFIER: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.universal_group_library.o .error_functions.o .SUBGROUP_EXAMPLIFIER.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.universal_group_library.o .error_functions.o .SUBGROUP_EXAMPLIFIER.o -o ../../../WORKBENCH/SUBGROUP_EXAMPLIFIER
