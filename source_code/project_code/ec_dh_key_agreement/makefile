../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

.ec_dh_key_agreement.o: ec_dh_key_agreement.c
	gcc -c ec_dh_key_agreement.c -o .ec_dh_key_agreement.o

ec_dh_key_agreement: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .ec_dh_key_agreement.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .ec_dh_key_agreement.o -o ../../../laboratory/ec_dh_key_agreement
