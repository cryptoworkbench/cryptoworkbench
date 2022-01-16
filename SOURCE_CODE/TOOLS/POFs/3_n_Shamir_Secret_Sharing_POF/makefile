../../../libraries/functional/.string.o: ../../../libraries/functional/string.h ../../../libraries/functional/string.c
	gcc -c ../../../libraries/functional/string.c -o ../../../libraries/functional/.string.o

../../../libraries/mathematics/.maths.o: ../../../libraries/mathematics/maths.h ../../../libraries/mathematics/maths.c
	gcc -c ../../../libraries/mathematics/maths.c -o ../../../libraries/mathematics/.maths.o

.3_n_Shamir_Secret_Sharing_POF.o: 3_n_Shamir_Secret_Sharing_POF.c
	gcc -c 3_n_Shamir_Secret_Sharing_POF.c -o .3_n_Shamir_Secret_Sharing_POF.o

3_n_Shamir_Secret_Sharing_POF: ../../../libraries/functional/.string.o ../../../libraries/mathematics/.maths.o .3_n_Shamir_Secret_Sharing_POF.o
	gcc ../../../libraries/functional/.string.o ../../../libraries/mathematics/.maths.o .3_n_Shamir_Secret_Sharing_POF.o -o ../../../../WORKBENCH/3_n_Shamir_Secret_Sharing_POF

