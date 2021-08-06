../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.LOGBOOK_library.o: ../../libraries/functional/LOGBOOK_library.h ../../libraries/functional/LOGBOOK_library.c
	gcc -c ../../libraries/functional/LOGBOOK_library.c -o ../../libraries/functional/.LOGBOOK_library.o

.REGISTRY_erase.o: REGISTRY_erase.c
	gcc -c REGISTRY_erase.c -o .REGISTRY_erase.o

REGISTRY_erase: .REGISTRY_erase.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o
	gcc .REGISTRY_erase.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o -o ../../../crypto_lab/instruments/REGISTRY_erase
