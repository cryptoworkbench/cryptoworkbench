# MAKES SUBGROUP_EXAMPLIFIER INTERACTIVE!
# Currently shift the amount of the modulus.
# Should cycle through a couple times.

#!/bin/bash

for i in $(seq 1 $1); do
    clear
    echo "Current horizontal shift: $i"; echo ""
    ./subgroup_examplifier $1 $2 "$i" 0;
    sleep 1
done
