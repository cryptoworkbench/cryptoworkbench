This is my implementation of the sieve of Eratosthenes.
This implementation of the sieve of Eratosthenes is nicely embedded within an interface for creating prime tables.

My most basic usage case would be:
'./prime\_table\_generator \<sieve limit>'

For example:
'./prime\_table\_generator 20'

This would make me generate an external prime table with all the primes greater than 1 and less than 20 in it.

I do like to store in the name of such a prime table file the number of primes within it.
Unfortunatly I do not know how many primes will be in a prime table until I finish generating it (sieve mechanics).
So I would write to 'primes\_less\_than\_100' and then rename to 'first\_25\_primes'; because there are 25 primes less than 100.
You get the idea: I use temporary filenames.

In order to output to stdout, append 'stdout', like this:
'./prime\_table\_generator 20 stdout'

When you put 'stdout' like this, there is no external prime table generated.

If you like to output to an external table file, but like my initial naming sceme better, put '--no-rename' or '-nr' instead. */
