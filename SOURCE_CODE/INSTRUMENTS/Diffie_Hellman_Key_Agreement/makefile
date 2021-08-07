../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/functional/.LOGBOOK_library.o: ../../libraries/functional/LOGBOOK_library.h ../../libraries/functional/LOGBOOK_library.c
	gcc -c ../../libraries/functional/LOGBOOK_library.c -o ../../libraries/functional/.LOGBOOK_library.o

.Diffie_Hellman_Key_Agreement.o: Diffie_Hellman_Key_Agreement.c
	gcc -c Diffie_Hellman_Key_Agreement.c -o .Diffie_Hellman_Key_Agreement.o

Diffie_Hellman_Key_Agreement: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/functional/.LOGBOOK_library.o .Diffie_Hellman_Key_Agreement.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/functional/.LOGBOOK_library.o .Diffie_Hellman_Key_Agreement.o -o ../../../WORKBENCH/INSTRUMENTS/Diffie_Hellman_Key_Agreement
