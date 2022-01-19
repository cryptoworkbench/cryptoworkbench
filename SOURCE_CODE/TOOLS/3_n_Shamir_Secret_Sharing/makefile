../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.3_n_Shamir_Secret_Sharing_ELABORATE.o: 3_n_Shamir_Secret_Sharing_ELABORATE.c
	gcc -c 3_n_Shamir_Secret_Sharing_ELABORATE.c -o .3_n_Shamir_Secret_Sharing_ELABORATE.o

3_n_Shamir_Secret_Sharing_ELABORATE: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .3_n_Shamir_Secret_Sharing_ELABORATE.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .3_n_Shamir_Secret_Sharing_ELABORATE.o -o ../../../WORKBENCH/3_n_Shamir_Secret_Sharing

.3_n_Shamir_Secret_Sharing_VERBOSE.o: 3_n_Shamir_Secret_Sharing_VERBOSE.c
	gcc -c 3_n_Shamir_Secret_Sharing_VERBOSE.c -o .3_n_Shamir_Secret_Sharing_VERBOSE.o

3_n_Shamir_Secret_Sharing_VERBOSE: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .3_n_Shamir_Secret_Sharing_VERBOSE.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .3_n_Shamir_Secret_Sharing_VERBOSE.o -o ../../../WORKBENCH/3_n_Shamir_Secret_Sharing

.3_n_Shamir_Secret_Sharing.o: 3_n_Shamir_Secret_Sharing.c
	gcc -c 3_n_Shamir_Secret_Sharing.c -o .3_n_Shamir_Secret_Sharing.o

3_n_Shamir_Secret_Sharing: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .3_n_Shamir_Secret_Sharing.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .3_n_Shamir_Secret_Sharing.o -o ../../../WORKBENCH/3_n_Shamir_Secret_Sharing
