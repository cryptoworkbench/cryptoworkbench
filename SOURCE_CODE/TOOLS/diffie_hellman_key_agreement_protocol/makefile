../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.universal_group_library.o: ../../libraries/mathematics/universal_group_library.h ../../libraries/mathematics/universal_group_library.c
	gcc -c ../../libraries/mathematics/universal_group_library.c -o ../../libraries/mathematics/.universal_group_library.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

.diffie_hellman_key_agreement_protocol.o: diffie_hellman_key_agreement_protocol.c
	gcc -c diffie_hellman_key_agreement_protocol.c -o .diffie_hellman_key_agreement_protocol.o

diffie_hellman_key_agreement_protocol: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.universal_group_library.o .diffie_hellman_key_agreement_protocol.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.universal_group_library.o .diffie_hellman_key_agreement_protocol.o -o ../../../WORKBENCH/diffie_hellman_key_agreement_protocol
