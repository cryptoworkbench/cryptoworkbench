../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/functional/.LOGBOOK_library.o: ../../libraries/functional/LOGBOOK_library.h ../../libraries/functional/LOGBOOK_library.c
	gcc -c ../../libraries/functional/LOGBOOK_library.c -o ../../libraries/functional/.LOGBOOK_library.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/mathematics/.group_operations.o: ../../libraries/mathematics/group_operations.h ../../libraries/mathematics/group_operations.c
	gcc -c ../../libraries/mathematics/group_operations.c -o ../../libraries/mathematics/.group_operations.o

.group_exporter.o: group_exporter.c
	gcc -c group_exporter.c -o .group_exporter.o

group_exporter: ../../libraries/functional/.string.o ../../libraries/functional/.LOGBOOK_library.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_operations.o .group_exporter.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o ../../libraries/functional/.string.o ../../libraries/functional/.triple_ref_pointers.o ../../libraries/mathematics/.group_operations.o .group_exporter.o -o ../../../crypto_lab/tools/group_exporter
