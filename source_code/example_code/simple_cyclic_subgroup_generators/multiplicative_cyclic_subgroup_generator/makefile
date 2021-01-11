maths.o: ../../libraries/functional/maths.c
	gcc -c ../../libraries/functional/maths.c -o ../../libraries/functional/maths.o

string_to_unsigned_long: ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.c ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.h
	gcc -c ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.c -o ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.o

gcd_of_two_numbers.o: ../../libraries/functional/gcd_of_two_numbers/gcd_of_two_numbers.c
	gcc -c ../../libraries/functional/gcd_of_two_numbers/gcd_of_two_numbers.c -o ../../libraries/functional/gcd_of_two_numbers/gcd_of_two_numbers.o

multiplicative_cyclic_subgroup_generator.o: multiplicative_cyclic_subgroup_generator.c
	gcc -c multiplicative_cyclic_subgroup_generator.c -o multiplicative_cyclic_subgroup_generator.o

multiplicative_cyclic_subgroup_generator: ../../libraries/functional/maths.o ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.o ../../libraries/functional/gcd_of_two_numbers/gcd_of_two_numbers.o multiplicative_cyclic_subgroup_generator.o
	gcc ../../libraries/functional/maths.o ../../libraries/functional/string_to_unsigned_long/string_to_unsigned_long.o ../../libraries/functional/gcd_of_two_numbers/gcd_of_two_numbers.o multiplicative_cyclic_subgroup_generator.o -o multiplicative_cyclic_subgroup_generator
