../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.least_common_multiple.o: least_common_multiple.c
	gcc -c least_common_multiple.c -o .least_common_multiple.o

least_common_multiple: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .least_common_multiple.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .least_common_multiple.o -o ../../../WORKBENCH/least_common_multiple
