../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.2_n_Shamir_Secret_Sharing_PROOF_OF_CONCEPT.o: 2_n_Shamir_Secret_Sharing_PROOF_OF_CONCEPT.c
	gcc -c 2_n_Shamir_Secret_Sharing_PROOF_OF_CONCEPT.c -o .2_n_Shamir_Secret_Sharing_PROOF_OF_CONCEPT.o

2_n_Shamir_Secret_Sharing_PROOF_OF_CONCEPT: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .2_n_Shamir_Secret_Sharing_PROOF_OF_CONCEPT.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .2_n_Shamir_Secret_Sharing_PROOF_OF_CONCEPT.o -o ../../../WORKBENCH/2_n_Shamir_Secret_Sharing_PROOF_OF_CONCEPT
