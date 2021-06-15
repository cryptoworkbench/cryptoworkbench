../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/functional/.logbook_functions.o: ../../libraries/functional/logbook_functions.h ../../libraries/functional/logbook_functions.c
	gcc -c ../../libraries/functional/logbook_functions.c -o ../../libraries/functional/.logbook_functions.o

../../libraries/functional/.modular_groups.o: ../../libraries/functional/modular_groups.h ../../libraries/functional/modular_groups.c
	gcc -c ../../libraries/functional/modular_groups.c -o ../../libraries/functional/.modular_groups.o

.dh_key_agreement.o: dh_key_agreement.c
	gcc -c dh_key_agreement.c -o .dh_key_agreement.o

dh_key_agreement: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.modular_groups.o .dh_key_agreement.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.modular_groups.o .dh_key_agreement.o -o ../../../workbench/dh_key_agreement
