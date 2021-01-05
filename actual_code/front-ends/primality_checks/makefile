string.o: ../../../libraries/mathematics/maths.c ../../../libraries/mathematics/maths.h ../../../libraries/functional/string.c ../../../libraries/functional/string.h
	cd ../../../libraries/functional && make string.o

table_lookup_library.o: ../../../libraries/mathematics/primality_checkers/table_lookup_library.c
	gcc -c ../../../libraries/mathematics/primality_checkers/table_lookup_library.c -o ../../../libraries/mathematics/primality_checkers/table_lookup_library.o

primality_checker.o: primality_checker.c
	gcc -c primality_checker.c -o primality_checker.o

.tester.o: .tester.c
	gcc -c .tester.c -o .tester.o

primality_checker: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o ../../../libraries/mathematics/primality_checkers/table_lookup_library/table_lookup_library.o primality_checker.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o ../../../libraries/mathematics/primality_checkers/table_lookup_library/table_lookup_library.o primality_checker.o -o primality_checker && rm ../../../libraries/mathematics/primality_checkers/table_lookup_library/table_lookup_library.o primality_checker.o

tester: ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o ../../../libraries/mathematics/primality_checkers/table_lookup_library/table_lookup_library.o .tester.o
	gcc ../../../libraries/mathematics/maths.o ../../../libraries/functional/string.o ../../../libraries/mathematics/primality_checkers/table_lookup_library/table_lookup_library.o .tester.o -o tester && rm .tester.o
