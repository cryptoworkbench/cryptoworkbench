../../libraries/functional/.string.o: ../../libraries/mathematics/maths.c ../../libraries/mathematics/maths.h ../../libraries/functional/string.c ../../libraries/functional/string.h
	cd ../../libraries/functional && make .string.o

../../libraries/functional/.linked_lists.o: ../../libraries/functional/linked_lists.h ../../libraries/functional/linked_lists.c
	gcc -c ../../libraries/functional/linked_lists.c -o ../../libraries/functional/.linked_lists.o

.general_subgroup_generator.o: general_subgroup_generator.c
	gcc -c general_subgroup_generator.c -o .general_subgroup_generator.o

general_subgroup_generator: ../../libraries/functional/.string.o ../../libraries/mathematics/.maths.o ../../libraries/functional/.linked_lists.o  .general_subgroup_generator.o
	gcc ../../libraries/mathematics/.maths.o ../../libraries/functional/.string.o ../../libraries/functional/.linked_lists.o .general_subgroup_generator.o -o ../../../workbench/general_subgroup_generator
	echo "APPLICATION 'general_subgroup_generator' is now ready in /workbench/"
