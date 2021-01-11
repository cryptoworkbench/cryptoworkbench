string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

general_subgroup_generator.o: general_subgroup_generator.c
	gcc -c general_subgroup_generator.c -o general_subgroup_generator.o

general_subgroup_generator: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o general_subgroup_generator.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o general_subgroup_generator.o -o ../../../actual_workbench/general_subgroup_generator && echo "APPLICATION 'outline' is now ready in /actual_workbench/" && rm general_subgroup_generator.o
