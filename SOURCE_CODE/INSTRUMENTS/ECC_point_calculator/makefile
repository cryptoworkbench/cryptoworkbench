../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.universal_group_library.o: ../../libraries/mathematics/universal_group_library.h ../../libraries/mathematics/universal_group_library.c
	gcc -c ../../libraries/mathematics/universal_group_library.c -o ../../libraries/mathematics/.universal_group_library.o

.ECC_point_calculator.o: ECC_point_calculator.c
	gcc -c ECC_point_calculator.c -o .ECC_point_calculator.o

ECC_point_calculator: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.universal_group_library.o .ECC_point_calculator.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.universal_group_library.o .ECC_point_calculator.o -o ../../../WORKBENCH/ECC_point_calculator
