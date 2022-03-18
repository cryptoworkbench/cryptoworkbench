../../libraries/functional/.string.o: ../../libraries/functional/string.h ../../libraries/functional/string.c
	gcc -c ../../libraries/functional/string.c -o ../../libraries/functional/.string.o

../../libraries/mathematics/.math.basic.o: ../../libraries/mathematics/math.basic.h ../../libraries/mathematics/math.basic.c
	gcc -c ../../libraries/mathematics/math.basic.c -o ../../libraries/mathematics/.math.basic.o

../../libraries/mathematics/.math.extended.o: ../../libraries/mathematics/math.extended.h ../../libraries/mathematics/math.extended.c
	gcc -c ../../libraries/mathematics/math.extended.c -o ../../libraries/mathematics/.math.extended.o

../../libraries/functional/.triple_ref_pointers.o: ../../libraries/functional/triple_ref_pointers.h ../../libraries/functional/triple_ref_pointers.c
	gcc -c ../../libraries/functional/triple_ref_pointers.c -o ../../libraries/functional/.triple_ref_pointers.o

.quadratic_residue.o: quadratic_residue.c
	gcc -c quadratic_residue.c -o .quadratic_residue.o

quadratic_residue: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o ../../libraries/functional/.triple_ref_pointers.o .quadratic_residue.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o ../../libraries/functional/.triple_ref_pointers.o .quadratic_residue.o -o ../../../applications/quadratic_residue

.quadratic_residue_with_root.o: quadratic_residue_with_root.c
	gcc -c quadratic_residue_with_root.c -o .quadratic_residue_with_root.o

quadratic_residue_with_root: ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o ../../libraries/functional/.triple_ref_pointers.o .quadratic_residue_with_root.o
	gcc ../../libraries/functional/.string.o ../../libraries/mathematics/.math.basic.o ../../libraries/mathematics/.math.extended.o ../../libraries/functional/.triple_ref_pointers.o .quadratic_residue_with_root.o -o ../../../applications/quadratic_residue_with_root
