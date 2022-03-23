../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/functional/.string.extended.o: ../../libraries/functional/string.extended.h ../../libraries/functional/string.extended.c
	gcc -c ../../libraries/functional/string.extended.c -o ../../libraries/functional/.string.extended.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

.least_common_multiple.o: least_common_multiple.c
	gcc -c least_common_multiple.c -o .least_common_multiple.o

least_common_multiple: ../../libraries/functional/.string.basic.o ../../libraries/functional/.string.extended.o ../../libraries/mathematics/.maths.basic.o .least_common_multiple.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/functional/.string.extended.o ../../libraries/mathematics/.maths.basic.o .least_common_multiple.o -o ../../../applications/least_common_multiple
