# Project description
Project cryptoworkbench is a project to create an environment for studying cryptography and the properties of numbers.

## Non-exclusive list of implemented mathematics
### The Sieve of Eratosthenes
[./actual\_code/project\_code/prime\_table\_generator/prime\_table\_generator.c](https://github.com/cryptoworkbench/cryptoworkbench/blob/main/actual_code/project_code/prime_table_generator/prime_table_generator.c) is the location of my implementation of the Sieve of Eratosthenes.
Here this ancient method for finding prime numbers comes in the form of a nice, ergonomic and intuitive generator of prime tables.
This prime table generator supports the generation of prime tables of both the binary and the ASCII flavours.

Example #1:
```bash
./actual_code/project_code/prime_table_generator/prime_table_generator 20 stdout
Complete list of primes less than 20:
2
3
5
7
11
13
17
19

8 primes printed to stdout.
```

Example #2

### Fermat's factorization algorithm
I especially like [./libraries/mathematics/factorization_engines/fermats_algorithm.c](https://github.com/cryptoworkbench/cryptoworkbench/blob/main/libraries/mathematics/factorization_engines/fermats_algorithm.c).
It's a library for factorizing odd composite numbers using Fermat's factorization algorithm. I am sincerely convinced this is the best possible implementation of Fermat's factorization algorithm in C. The leanest, meanest, and cleanest code imaginable.


See [./actual_code/example_code/library_drivers/fermat_factorization/](https://github.com/cryptoworkbench/cryptoworkbench/tree/main/actual_code/example_code/library_drivers/fermat_factorization) for two front-ends for this factorization engine.

Ps. These frontends can of course be generalized to any factorization engine.
