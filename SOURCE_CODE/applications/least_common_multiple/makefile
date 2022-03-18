../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.basic.o: ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	gcc -c ../../libraries/mathematics/math.basic.c -o ../../libraries/mathematics/.math.basic.o

.least_common_multiple.o: least_common_multiple.c
	gcc -c least_common_multiple.c -o .least_common_multiple.o

least_common_multiple: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o .least_common_multiple.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o .least_common_multiple.o -o ../../../applications/least_common_multiple
