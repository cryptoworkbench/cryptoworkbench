../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/mathematics/.math_extended.o: ../../libraries/mathematics/math_extended.h ../../libraries/mathematics/math_extended.c ../../libraries/mathematics/math_basic.h ../../libraries/mathematics/math_basic.c
	cd ../../libraries/mathematics && make math_extended_LIBRARY

../../libraries/mathematics/.group_library.o: ../../libraries/mathematics/group_library.h ../../libraries/mathematics/group_library.c
	gcc -c ../../libraries/mathematics/group_library.c -o ../../libraries/mathematics/.group_library.o

.group_element_exporter.o: group_element_exporter.c
	gcc -c group_element_exporter.c -o .group_element_exporter.o

group_element_exporter: ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .group_element_exporter.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o .group_element_exporter.o -o ../../../applications/group_element_exporter
