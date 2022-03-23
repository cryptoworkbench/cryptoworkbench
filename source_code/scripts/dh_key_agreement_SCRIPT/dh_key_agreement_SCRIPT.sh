# Proves multiplication stays associative (commutative?, distributive?) under a finite field.
#
# Refreshes every two seconds.
#!/bin/bash

if [ -z "$3" ];
then echo "Please set the refresh rate as third argument (in seconds). Exiting '-1'. Goodbye."; exit -1;
else for i in {6..1..1}; do clear; echo "Examplifying the Diffie-Hellman key agreement with random private values every $3 second(s)."; echo ""; echo "Starting in $i .. .."; sleep 1; done fi
while true; do clear; ./dh_key_agreement $1 $2; if [[ "$?" != '0' ]]; then break; fi; sleep $3; done
