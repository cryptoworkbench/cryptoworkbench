# MAKES SUBGROUP_EXAMPLIFIER INTERACTIVE!
#
# SUPPLY:
# ~ as first argument the modulus
# ~ as second argument the group's identity
# ~ as third argument the refresh rate
#
# A fourth argument can be supplied in order to set the vertical offset throughout loop-time.
# 
# DEVELOPER NOTICE:
# Currently shifts in total the amount of the modulus.
# I'd prefer it if it cycled through at least three times.

#!/bin/bash

for i in $(seq 1 $1); do
    clear
    echo "Current horizontal offset: $i
    ";
    ./subgroup_examplifier $1 $2 "$i" $4;
    echo "
    ";
    echo "refresh rate: every $3 s.
    ";
    sleep $3
done
