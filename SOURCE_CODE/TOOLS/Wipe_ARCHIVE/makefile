../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.LOGBOOK_library.o: ../../libraries/functional/LOGBOOK_library.h ../../libraries/functional/LOGBOOK_library.c
	gcc -c ../../libraries/functional/LOGBOOK_library.c -o ../../libraries/functional/.LOGBOOK_library.o

.Wipe_ARCHIVE.o: Wipe_ARCHIVE.c
	gcc -c Wipe_ARCHIVE.c -o .Wipe_ARCHIVE.o

Wipe_ARCHIVE: .Wipe_ARCHIVE.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o
	gcc .Wipe_ARCHIVE.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o -o ../../../WORKBENCH/Wipe_ARCHIVE && .Wipe_ARCHIVE.o
