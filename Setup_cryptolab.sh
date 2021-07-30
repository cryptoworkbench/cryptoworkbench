#!/bin/bash 

mkdir crypto_lab/
mkdir crypto_lab/tools
mkdir crypto_lab/registry

cd source_code/tools/group_examplifier && make group_examplifier && echo "### The following instrument has been assemblied/linked: group_examplifier
"
cd ../subgroup_examplifier && make subgroup_examplifier && echo "### The following instrument has been assemblied/linked: subgroup_examplifier
"
cd ../Diffie_Hellman_Key_Agreement && make Diffie_Hellman_Key_Agreement && echo "### The following instrument has been assemblied/linked: Diffie_Hellman_Key_Agreement
"
cd ../cayley_table_generator && make cayley_table_generator && echo "### The following instrument has been assemblied/linked: cayley_table_generator
"
cd ../prime_table_generator && make prime_table_generator && echo "### The following instrument has been assemblied/linked: prime_table_generator
"
cd ../modular_exponentiation && make modular_exponentiation && echo "### The following instrument has been assemblied/linked: modular_exponentiation
"
cd ../CLEAR_LABORATORY_LOGBOOK && make CLEAR_LABORATORY_LOGBOOK && echo "### The following instrument has been assemblied/linked: CLEAR_LABORATORY_LOGBOOK
"
cd ../CLEAR_REGISTRY && make CLEAR_REGISTRY && echo "### The following instrument has been assemblied/linked: CLEAR_REGISTRY"

echo "
##### Halting the assembly line ... ... ...
########################################################################################################
##### Setup complete 'cd crypto_lab/tools/' TO ENTER YOUR VERY OWN VIRTUAL MATHEMATICS LABORATORY. #####"
