maths.o: ../../libraries/functional/maths.c
	gcc -c ../../libraries/functional/maths.c -o ../../libraries/functional/maths.o

string_to_unsigned_long: ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.c ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.h
	gcc -c ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.c -o ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.o

additive_cyclic_subgroup_generator.o: additive_cyclic_subgroup_generator.c
	gcc -c additive_cyclic_subgroup_generator.c -o additive_cyclic_subgroup_generator.o

additive_cyclic_subgroup_generator: ../../libraries/functional/maths.o ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.o additive_cyclic_subgroup_generator.o
	gcc ../../libraries/functional/maths.o ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.o additive_cyclic_subgroup_generator.o -o additive_cyclic_subgroup_generator
