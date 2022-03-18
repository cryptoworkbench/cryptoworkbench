../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.extended.o: ../../libraries/mathematics/math.extended.h ../../libraries/mathematics/math.extended.c ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	cd ../../libraries/mathematics && make math.extended_LIBRARY

../../libraries/mathematics/.shamir_secret_sharing.o: ../../libraries/mathematics/shamir_secret_sharing.h ../../libraries/mathematics/shamir_secret_sharing.c
	gcc -c ../../libraries/mathematics/shamir_secret_sharing.c -o ../../libraries/mathematics/.shamir_secret_sharing.o

.2_n_Shamir_Secret_Sharing.o: 2_n_Shamir_Secret_Sharing.c
	gcc -c 2_n_Shamir_Secret_Sharing.c -o .2_n_Shamir_Secret_Sharing.o

2_n_Shamir_Secret_Sharing: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.extended.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.shamir_secret_sharing.o .2_n_Shamir_Secret_Sharing.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.extended.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.shamir_secret_sharing.o .2_n_Shamir_Secret_Sharing.o -o ../../../applications/2_n_Shamir_Secret_Sharing
