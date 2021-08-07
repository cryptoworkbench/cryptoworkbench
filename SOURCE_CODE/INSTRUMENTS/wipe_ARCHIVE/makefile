../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.LOGBOOK_library.o: ../../libraries/functional/LOGBOOK_library.h ../../libraries/functional/LOGBOOK_library.c
	gcc -c ../../libraries/functional/LOGBOOK_library.c -o ../../libraries/functional/.LOGBOOK_library.o

.wipe_ARCHIVE.o: wipe_ARCHIVE.c
	gcc -c wipe_ARCHIVE.c -o .wipe_ARCHIVE.o

wipe_ARCHIVE: .wipe_ARCHIVE.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o
	gcc .wipe_ARCHIVE.o ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o -o ../../../WORKBENCH/INSTRUMENTS/wipe_ARCHIVE
