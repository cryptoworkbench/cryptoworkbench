../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/functional/.logbook_functions.o: ../../libraries/functional/logbook_functions.c ../../libraries/functional/logbook_functions.h
	gcc -c ../../libraries/functional/logbook_functions.c -o ../../libraries/functional/.logbook_functions.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.c ../../libraries/functional/triple_ref_pointers.h
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

.shared_information.o: shared_information.c
	gcc -c shared_information.c -o .shared_information.o

.chain.o: chain.c
	gcc -c chain.c -o .chain.o

chain: ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.triple_ref_pointers.o .shared_information.o .chain.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.triple_ref_pointers.o .shared_information.o .chain.o -o ../../../crypto_lab/instruments/chain


.endpoint_alice.o: endpoint_alice.c
	gcc -c endpoint_alice.c -o .endpoint_alice.o

endpoint_alice: ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.triple_ref_pointers.o .shared_information.o .endpoint_alice.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.triple_ref_pointers.o .shared_information.o .endpoint_alice.o -o ../../../crypto_lab/instruments/.endpoint_alice

.endpoint_bob.o: endpoint_bob.c
	gcc -c endpoint_bob.c -o .endpoint_bob.o

endpoint_bob: ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.triple_ref_pointers.o .shared_information.o .endpoint_bob.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.logbook_functions.o ../../libraries/functional/.triple_ref_pointers.o .shared_information.o .endpoint_bob.o -o ../../../crypto_lab/instruments/.endpoint_bob
