# Project description
My project is to create an environment for studying cryptography and the properties of numbers.

## Non-exclusive list of implemented mathematics
### The Sieve of Eratosthenes
My implementation of the Sieve of Eratosthenes is located at [/actual\_code/project\_code/prime\_table\_generator/](https://github.com/cryptoworkbench/cryptoworkbench/tree/main/actual_code/project_code/prime_table_generator).
Here this ancient method for finding prime numbers comes in the packaging of a nice, easy to use and _ergonomic_ generator of prime tables.
This prime table generator can generate compact binary prime tables but also basic ASCII tables one can 'cat' or alternatively load intelligibly into vim.
Of course this generator can also output back into the terminal (stdout).

Example:
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

### Fermat's factorization algorithm
I especially like '/libraries/mathematics/factorization\_engines/fermats\_algorithm.c'
It's a library I wrote for factorizing composite numbers using Fermat's algorithm.

See /actual\_code/example\_code/library\_drivers/fermat\_factorization/ for two front-ends for this factorization engine.
PS. Front-ends can of course be generalized to any factorization engine.
