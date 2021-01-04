From the outside, _from the perspective of my executable_, you could probably only percieve of me as some sort of a remarkably cool prime table generator.

_This I am_, but at my core I still am an implementation of the sieve of Eratosthenes.

My _most_ basic usage case would be:
```bash
./prime_table_generator <sieve limit>
```

For example:
```bash
./prime_table_generator 20
```

Running this command would make me generate an external prime table with all the primes greater than 1 and less than 20 in it (of either the binary or the ASCII flavour).

I do like to mention a prime table's number of primes in it's filename. Unfortunately however, when I open a new filestream in order to output a new prime table, I do not yet know how many primes will be in there by the time that I close this new filestream (a pitfall of using Eratosthenes's sieve for finding prime numbers that inherently cannot be dealt with, since it's intrinsic to it's methodology). In this example I output to initial filename "primes\_less\_than\_20".

Then I rename "primes\_less\_than\_20" to "first\_8\_primes" because there are 8 primes less than 20:
```bash
mv primes_less_than_20 first_8_primes
```

To prevent me from renaming you can use both "--no-rename" and "-nr":
```bash
./prime_table_generator 20 --no-rename
```
```bash
./prime_table_generator 20 -nr
```

Or alternatively in order to prevent me from generating an external file at all try appending "stdout":
```bash
./prime_table_generator 20 stdout
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
