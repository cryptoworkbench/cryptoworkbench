../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/mathematics/.group_library.o: ../../libraries/mathematics/group_library.h ../../libraries/mathematics/group_library.c
	gcc -c ../../libraries/mathematics/group_library.c -o ../../libraries/mathematics/.group_library.o

.group_element_exporter.o: group_element_exporter.c
	gcc -c group_element_exporter.c -o .group_element_exporter.o

group_element_exporter: ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .group_element_exporter.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o .group_element_exporter.o -o ../../../applications/group_element_exporter
