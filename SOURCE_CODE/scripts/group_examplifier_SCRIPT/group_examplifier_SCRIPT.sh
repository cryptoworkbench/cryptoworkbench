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

if [ -z "$3" ];
then echo "Please set the cycle rate as third argument (in seconds). Exiting '-1'. Goodbye."; exit -1;
else for i in {9..1..1}; do
    clear;
    echo "Examplifying the cyclic subgroups of the group identified by characteristics 'modulus = $1' && 'identity = $2'"; echo "";
    echo "Cycling through the cyclic subgroups exactly 1 step per $3 second(s)."; echo ""; echo "Starting in $i .. .."; sleep 1; done
fi

i=0; while true; do clear; echo "Current horizontal offset: $i"; echo ""; ./group_examplifier $1 $2 "$i" $4; echo ""; echo "refresh rate: every $3s."; i=$(( $i + 1 )); sleep $3; done
