../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.universal_group_library.o: ../../libraries/mathematics/universal_group_library.h ../../libraries/mathematics/universal_group_library.c
	gcc -c ../../libraries/mathematics/universal_group_library.c -o ../../libraries/mathematics/.universal_group_library.o

.ERROR_FUNCTIONS.o: ERROR_FUNCTIONS.h ERROR_FUNCTIONS.c
	gcc -c ERROR_FUNCTIONS.c -o .ERROR_FUNCTIONS.o

.SUBGROUP_EXAMPLIFIER.o: SUBGROUP_EXAMPLIFIER.c
	gcc -c SUBGROUP_EXAMPLIFIER.c -o .SUBGROUP_EXAMPLIFIER.o

SUBGROUP_EXAMPLIFIER: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.universal_group_library.o .ERROR_FUNCTIONS.o .SUBGROUP_EXAMPLIFIER.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.universal_group_library.o .ERROR_FUNCTIONS.o .SUBGROUP_EXAMPLIFIER.o -o ../../../WORKBENCH/SUBGROUP_EXAMPLIFIER
