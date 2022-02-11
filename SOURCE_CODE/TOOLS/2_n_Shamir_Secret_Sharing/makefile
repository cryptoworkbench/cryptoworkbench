../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.sharmir_secret_sharing.o: ../../libraries/mathematics/shamir_secret_sharing.h ../../libraries/mathematics/shamir_secret_sharing.c
	gcc -c ../../libraries/mathematics/shamir_secret_sharing.c -o ../../libraries/mathematics/.shamir_secret_sharing.o

.2_n_Shamir_Secret_Sharing.o: 2_n_Shamir_Secret_Sharing.c
	gcc -c 2_n_Shamir_Secret_Sharing.c -o .2_n_Shamir_Secret_Sharing.o

2_n_Shamir_Secret_Sharing: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.shamir_secret_sharing.o .2_n_Shamir_Secret_Sharing.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.shamir_secret_sharing.o .2_n_Shamir_Secret_Sharing.o -o ../../../WORKBENCH/2_n_Shamir_Secret_Sharing
