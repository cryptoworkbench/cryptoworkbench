# A simple script which (using the TOOL 'prime_factorize') prints all prime factorizations less than the number specified as first argument.
# A second argument may be supplied which is passed onto 'prime_factorize'.
#
# USING:
#!/bin/bash 

for i in $(seq 2 $1); do ./prime_factorize "$i" $2 2> a; done
