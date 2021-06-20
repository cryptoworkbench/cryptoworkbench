../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/functional/.logbook_functions.o: ../../libraries/functional/logbook_functions.h ../../libraries/functional/logbook_functions.c
	gcc -c ../../libraries/functional/logbook_functions.c -o ../../libraries/functional/.logbook_functions.o

../../libraries/functional/.registry_functions.o: ../../libraries/functional/registry_functions.h ../../libraries/functional/registry_functions.c
	gcc -c ../../libraries/functional/registry_functions.c -o ../../libraries/functional/.registry_functions.o

.dh_key_agreement.o: dh_key_agreement.c
	gcc -c dh_key_agreement.c -o .dh_key_agreement.o

dh_key_agreement: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.registry_functions.o .dh_key_agreement.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.registry_functions.o .dh_key_agreement.o -o ../../../laboratory/dh_key_agreement
