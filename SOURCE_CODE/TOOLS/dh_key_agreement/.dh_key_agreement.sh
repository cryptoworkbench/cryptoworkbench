# Proves multiplication stays associative (commutative?) under a finite field.
#
# Refreshes every two seconds.
#!/bin/bash

while true
do
    clear
    ./dh_key_agreement $1 $2
    sleep 2
done
