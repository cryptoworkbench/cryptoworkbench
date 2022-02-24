# I am currently trying to rewrite 2_n_Shamir_Secret_Sharing to store the equations in unsigned long arrays instead of arrays of unsigned long pointers pointing to fragmentated pieces of the coefficient 'string'
# This I am trying to achieve seperately from 'shamir_secret_sharing.c' in 'sss.c'
# Later when I have also adapted 3_n_Shamir_Secret_Sharing I will remove 'shamir_secret_sharing.c' and rename 'sss.c' to 'shamir_secret_sharing.c' therafter.

../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.sss.o: ../../libraries/mathematics/sss.h ../../libraries/mathematics/sss.c
	gcc -c ../../libraries/mathematics/sss.c -o ../../libraries/mathematics/.sss.o

.2_n_Shamir_Secret_Sharing.o: 2_n_Shamir_Secret_Sharing.c
	gcc -c 2_n_Shamir_Secret_Sharing.c -o .2_n_Shamir_Secret_Sharing.o

2_n_Shamir_Secret_Sharing: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.sss.o .2_n_Shamir_Secret_Sharing.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/mathematics/.sss.o .2_n_Shamir_Secret_Sharing.o -o ../../../WORKBENCH/2_n_Shamir_Secret_Sharing
