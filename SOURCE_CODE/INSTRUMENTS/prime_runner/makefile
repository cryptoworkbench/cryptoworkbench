../../libraries/mathematics/.maths.o: ../../libraries/mathematics/maths.h ../../libraries/mathematics/maths.c
	gcc -c ../../libraries/mathematics/maths.c -o ../../libraries/mathematics/.maths.o

../../libraries/functional/.ERROR.o: ../../libraries/functional/ERROR.h ../../libraries/functional/ERROR.c
	gcc -c ../../libraries/functional/ERROR.c -o ../../libraries/functional/.ERROR.o

../../libraries/functional/.SIGNAL.o: ../../libraries/functional/SIGNAL.h ../../libraries/functional/SIGNAL.c
	gcc -c ../../libraries/functional/SIGNAL.c -o ../../libraries/functional/.SIGNAL.o

../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

.prime_runner.o: prime_runner.c
	gcc -c prime_runner.c -o .prime_runner.o

prime_runner: ../../libraries/mathematics/.maths.o ../../libraries/functional/.ERROR.o ../../libraries/functional/.SIGNAL.o ../../libraries/functional/.string.o .prime_runner.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.ERROR.o ../../libraries/functional/.SIGNAL.o ../../libraries/functional/.string.o .prime_runner.o -o prime_runner
