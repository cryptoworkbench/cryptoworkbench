../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.LOGBOOK_library.o: ../../libraries/functional/LOGBOOK_library.h ../../libraries/functional/LOGBOOK_library.c
	gcc -c ../../libraries/functional/LOGBOOK_library.c -o ../../libraries/functional/.LOGBOOK_library.o

../../libraries/mathematics/.group_operations.o: ../../libraries/mathematics/group_operations.h ../../libraries/mathematics/group_operations.c
	gcc -c ../../libraries/mathematics/group_operations.c -o ../../libraries/mathematics/.group_operations.o

.ID_from_fnct_ptr.o: ID_from_fnct_ptr.c
	gcc -c ID_from_fnct_ptr.c -o .ID_from_fnct_ptr.o

ID_from_fnct_ptr: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o ../../libraries/mathematics/.group_operations.o .ID_from_fnct_ptr.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.LOGBOOK_library.o ../../libraries/mathematics/.group_operations.o .ID_from_fnct_ptr.o -o ID_from_fnct_ptr && rm .ID_from_fnct_ptr.o
