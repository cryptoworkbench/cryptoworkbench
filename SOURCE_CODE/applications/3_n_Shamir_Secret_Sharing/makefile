../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

../../libraries/mathematics/.shamir_secret_sharing.o: ../../libraries/mathematics/shamir_secret_sharing.h ../../libraries/mathematics/shamir_secret_sharing.c
	gcc -c ../../libraries/mathematics/shamir_secret_sharing.c -o ../../libraries/mathematics/.shamir_secret_sharing.o

.3_n_Shamir_Secret_Sharing.o: 3_n_Shamir_Secret_Sharing.c
	gcc -c 3_n_Shamir_Secret_Sharing.c -o .3_n_Shamir_Secret_Sharing.o

3_n_Shamir_Secret_Sharing: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/mathematics/.shamir_secret_sharing.o .3_n_Shamir_Secret_Sharing.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/mathematics/.shamir_secret_sharing.o .3_n_Shamir_Secret_Sharing.o -o ../../../applications/3_n_Shamir_Secret_Sharing
