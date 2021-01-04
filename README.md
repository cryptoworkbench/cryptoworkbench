# Project description
My project is to create an environment for studying cryptography and the properties of numbers.

## Non-exclusive list of implemented mathematics
### The Sieve of Eratosthenes
My implementation of the Sieve of Eratosthenes is located at '/actual\_code/project\_code/prime\_table\_generator/prime\_table\_generator.c'.
Here this ancient method for finding prime numbers comes in the packaging of a nice, easy to use and _ergonomic_ generator of prime tables.
This prime table generator can generate compact binary prime tables but also basic ASCII tables that one can 'cat' and intelligibly load into vim.

### Fermat's factorization algorithm
I especially like '/libraries/mathematics/factorization\_engines/fermats\_algorithm.c'
It's a library I wrote for factorizing composite numbers using Fermat's algorithm.

See /actual\_code/example\_code/library\_drivers/fermat\_factorization/ for two front-ends for this factorization engine.
PS. Front-ends can of course be generalized to any factorization engine.
