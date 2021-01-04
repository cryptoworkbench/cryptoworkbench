From the outside, _from the perspective of my executable_, you could probably only percieve of me as some sort of a remarkably cool prime table generator.

_This I am_, but at my core I stay an implementation of the sieve of Eratosthenes.

My _most_ basic usage case would be:
```bash
./prime\_table\_generator <sieve limit>
```

For example:
```bash
./prime\_table\_generator 20
```

This command would make me generate an external prime table with all the primes greater than 1 and less than 20 in it.

I do like to store in the name of such a prime table file the number of primes within it.
Unfortunately however, at the moment when I open a new filestream for generating such an external prime table file, I do not yet know how many primes will be in there by the time that I close this filestream (a pitfall of using Eratosthenes's sieve for finding prime numbers that inherently cannot be dealt with, since it's intrinsic to it's methodology). So initially I'd output to 'primes\_less\_than\_20'.

Then, since there are 8 primes in between 1 and 20, I actually
```bash
mv primes_less_than_20 first_8_primes
```
In order to output to stdout, append 'stdout', like this:
```bash
./prime_table_generator 20 stdout
```

When you put 'stdout' like this, there is no external prime table generated.

If you like to output to an external table file, but like my initial naming sceme better, put '--no-rename' or '-nr' instead. */
