../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/functional/.string.extended.o: ../../libraries/functional/string.extended.h ../../libraries/functional/string.extended.c
	gcc -c ../../libraries/functional/string.extended.c -o ../../libraries/functional/.string.extended.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.groups.o: ../../libraries/mathematics/maths.groups.h ../../libraries/mathematics/maths.groups.c
	gcc -c ../../libraries/mathematics/maths.groups.c -o ../../libraries/mathematics/.maths.groups.o

.group_combine.o: group_combine.c
	gcc -c group_combine.c -o .group_combine.o

group_combine: ../../libraries/functional/.string.basic.o ../../libraries/functional/.string.extended.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.groups.o .group_combine.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/functional/.string.extended.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.groups.o .group_combine.o -o ../../../applications/group_combine
