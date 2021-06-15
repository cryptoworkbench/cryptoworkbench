../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/functional/.logbook_functions.o: ../../libraries/functional/logbook_functions.h ../../libraries/functional/logbook_functions.c
	gcc -c ../../libraries/functional/logbook_functions.c -o ../../libraries/functional/.logbook_functions.o

.dh_key_agreement_examplifier.o: dh_key_agreement_examplifier.c
	gcc -c dh_key_agreement_examplifier.c -o .dh_key_agreement_examplifier.o

dh_key_agreement_examplifier: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/functional/.logbook_functions.o .dh_key_agreement_examplifier.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/functional/.logbook_functions.o .dh_key_agreement_examplifier.o -o ../../../workbench/dh_key_agreement_examplifier
