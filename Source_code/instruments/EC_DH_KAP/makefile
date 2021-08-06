../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

.EC_DH_KAP.o: EC_DH_KAP.c
	gcc -c EC_DH_KAP.c -o .EC_DH_KAP.o

EC_DH_KAP: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .EC_DH_KAP.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o .EC_DH_KAP.o -o ../../../crypto_lab/instruments/EC_DH_KAP
