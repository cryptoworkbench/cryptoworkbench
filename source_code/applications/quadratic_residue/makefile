../../libraries/functional/.string.basic.o: ../../libraries/functional/string.basic.h ../../libraries/functional/string.basic.c
	gcc -c ../../libraries/functional/string.basic.c -o ../../libraries/functional/.string.basic.o

../../libraries/mathematics/.maths.basic.o: ../../libraries/mathematics/maths.basic.h ../../libraries/mathematics/maths.basic.c
	gcc -c ../../libraries/mathematics/maths.basic.c -o ../../libraries/mathematics/.maths.basic.o

../../libraries/mathematics/.maths.extended.o: ../../libraries/mathematics/maths.extended.h ../../libraries/mathematics/maths.extended.c
	gcc -c ../../libraries/mathematics/maths.extended.c -o ../../libraries/mathematics/.maths.extended.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

.quadratic_residue.o: quadratic_residue.c
	gcc -c quadratic_residue.c -o .quadratic_residue.o

quadratic_residue: ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/functional/.triple_ref_pointers.o .quadratic_residue.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/functional/.triple_ref_pointers.o .quadratic_residue.o -o ../../../applications/quadratic_residue

.quadratic_residue_with_root.o: quadratic_residue_with_root.c
	gcc -c quadratic_residue_with_root.c -o .quadratic_residue_with_root.o

quadratic_residue_with_root: ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/functional/.triple_ref_pointers.o .quadratic_residue_with_root.o
	gcc ../../libraries/functional/.string.basic.o ../../libraries/mathematics/.maths.basic.o ../../libraries/mathematics/.maths.extended.o ../../libraries/functional/.triple_ref_pointers.o .quadratic_residue_with_root.o -o ../../../applications/quadratic_residue_with_root
