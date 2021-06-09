../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

.diffie-hellman_key_agreement_protocol.o: diffie-hellman_key_agreement_protocol.c
	gcc -c diffie-hellman_key_agreement_protocol.c -o .diffie-hellman_key_agreement_protocol.o

diffie-hellman_key_agreement_protocol: ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o .diffie-hellman_key_agreement_protocol.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o .diffie-hellman_key_agreement_protocol.o -o ../../../workbench/diffie-hellman_key_agreement_protocol
