string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

working.o: working.c
	gcc -c working.c -o working.o

working: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o working.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o working.o -o working && rm working.o

prototype.o: prototype.c
	gcc -c prototype.c -o prototype.o

prototype: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o prototype.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o prototype.o -o prototype && rm prototype.o
