../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

.diffie_hellman_key_agreement_protocol.o: diffie_hellman_key_agreement_protocol.c
	gcc -c diffie_hellman_key_agreement_protocol.c -o .diffie_hellman_key_agreement_protocol.o

diffie_hellman_key_agreement_protocol: ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.triple_ref_pointers.o .diffie_hellman_key_agreement_protocol.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.triple_ref_pointers.o .diffie_hellman_key_agreement_protocol.o -o ../../../workbench/diffie_hellman_key_agreement_protocol
