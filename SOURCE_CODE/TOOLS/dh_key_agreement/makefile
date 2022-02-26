../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.group_library.o: ../../libraries/mathematics/group_library.h ../../libraries/mathematics/group_library.c
	gcc -c ../../libraries/mathematics/group_library.c -o ../../libraries/mathematics/.group_library.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

.dh_key_agreement.o: dh_key_agreement.c
	gcc -c dh_key_agreement.c -o .dh_key_agreement.o

dh_key_agreement: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_library.o .dh_key_agreement.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_library.o .dh_key_agreement.o -o ../../../WORKBENCH/dh_key_agreement
