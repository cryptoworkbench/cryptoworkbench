../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math_extended.o: ../../libraries/mathematics/math_extended.h ../../libraries/mathematics/math_extended.c ../../libraries/mathematics/math_basic.h ../../libraries/mathematics/math_basic.c
	cd ../../libraries/mathematics && make math_extended_LIBRARY

.least_common_multiple.o: least_common_multiple.c
	gcc -c least_common_multiple.c -o .least_common_multiple.o

least_common_multiple: ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .least_common_multiple.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .least_common_multiple.o -o ../../../applications/least_common_multiple
