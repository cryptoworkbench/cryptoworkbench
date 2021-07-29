../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.LOGBOOK_library.o: ../../libraries/functional/LOGBOOK_library.h ../../libraries/functional/LOGBOOK_library.c
	gcc -c ../../libraries/functional/LOGBOOK_library.c -o ../../libraries/functional/.LOGBOOK_library.o

.CLEAR_REGISTRY_prototype.o: .CLEAR_REGISTRY_prototype.c
	gcc -c .CLEAR_REGISTRY_prototype.c -o .CLEAR_REGISTRY_prototype.o

CLEAR_REGISTRY_prototype: .CLEAR_REGISTRY_prototype.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o
	gcc .CLEAR_REGISTRY_prototype.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o -o ../../../crypto_lab/tools/.CLEAR_REGISTRY_prototype && rm .CLEAR_REGISTRY_prototype.o

.CLEAR_REGISTRY.o: CLEAR_REGISTRY.c
	gcc -c CLEAR_REGISTRY.c -o .CLEAR_REGISTRY.o

CLEAR_REGISTRY: .CLEAR_REGISTRY.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o
	gcc .CLEAR_REGISTRY.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o -o ../../../crypto_lab/tools/.CLEAR_REGISTRY
