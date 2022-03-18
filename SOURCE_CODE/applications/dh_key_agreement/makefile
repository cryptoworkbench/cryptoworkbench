../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math_extended.o: ../../libraries/mathematics/math_extended.h ../../libraries/mathematics/math_extended.c ../../libraries/mathematics/math_basic.h ../../libraries/mathematics/math_basic.c
	cd ../../libraries/mathematics && make math_extended_LIBRARY

../../libraries/mathematics/.group_library.o: ../../libraries/mathematics/group_library.h ../../libraries/mathematics/group_library.c
	gcc -c ../../libraries/mathematics/group_library.c -o ../../libraries/mathematics/.group_library.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

.dh_key_agreement.o: dh_key_agreement.c
	gcc -c dh_key_agreement.c -o .dh_key_agreement.o

dh_key_agreement: ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_library.o .dh_key_agreement.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math_basic.o ../../libraries/mathematics/.math_extended.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_library.o .dh_key_agreement.o -o ../../../applications/dh_key_agreement
