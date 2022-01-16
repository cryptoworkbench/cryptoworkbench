../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

.3_N_Shamir_Secret_Sharing.o: 3_N_Shamir_Secret_Sharing.c
	gcc -c 3_N_Shamir_Secret_Sharing.c -o .3_N_Shamir_Secret_Sharing.o

3_N_Shamir_Secret_Sharing: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .3_N_Shamir_Secret_Sharing.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .3_N_Shamir_Secret_Sharing.o -o ../../../WORKBENCH/3_N_Shamir_Secret_Sharing

