../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.group_operation.o: group_operation.c
	gcc -c group_operation.c -o .group_operation.o

group_operation: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .group_operation.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .group_operation.o -o ../../../TOOLS/group_operation
