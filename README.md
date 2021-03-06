# Project description
The idea is to create a virtual mathematics laboratory. A laboratory whose instruments that can be accessed through the Linux terminal.

To get started using my environment, go to the directory in which you with to install to and execute the following commands:

    # git clone https://github.com/cryptoworkbench/cryptoworkbench.git
    # cd cryptoworkbench/workbench
    # chmod +x setup_workbench.sh && ./setup_workbench.sh
    # export PATH=$(pwd):$PATH && echo "export PATH=$(pwd):\$PATH" | tee -a /home/$USER/.bashrc >/dev/null

This will initialize my repository on your computer and add the "workbench/" folder to your $PATH variable so you can acess it's tools from everywhere.

## Non-exclusive list of implemented mathematics
### The Sieve of Eratosthenes
[./source_code/project_code/prime_table_generator/prime_table_generator.c](https://github.com/cryptoworkbench/cryptoworkbench/blob/main/source_code/project_code/prime_table_generator/prime_table_generator.c) is my implementation of the Sieve of Eratosthenes.
Here this ancient method for finding prime numbers comes in the form of a nice, ergonomic and intuitive generator of prime tables.
This prime table generator supports the generation of prime tables of both the binary and the ASCII flavours.
Two general use cases follow below.

#### Use case \#1. _Generating prime tables:_
```bash
# prime_table_generator 1000000
Enable binary mode (0/1): 1

78498 primes printed to binary file 'first_78498_primes'.
```

#### Use case \#2. _Quickly inspecting of the first few primes:_
```bash
# prime_table_generator 20 stdout
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
I especially like [./libraries/mathematics/factorization_engines/fermats_algorithm.c](https://github.com/cryptoworkbench/cryptoworkbench/blob/main/libraries/mathematics/factorization_engines/fermats_algorithm.c).
It's a library for factorizing odd composite numbers using Fermat's factorization algorithm. I am sincerely convinced this is the best possible implementation of Fermat's factorization algorithm in C. Literally the leanest, meanest, and cleanest code imaginable.


See [./source_code/example_code/library_drivers/fermat_factorization/](https://github.com/cryptoworkbench/cryptoworkbench/tree/main/source_code/example_code/library_drivers/fermat_factorization) for two front-ends for this factorization engine.

Ps. These frontends can of course be generalized to any factorization engine.
