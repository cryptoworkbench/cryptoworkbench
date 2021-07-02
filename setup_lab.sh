#!/bin/bash 

mkdir crypto_lab/
mkdir crypto_lab/tools
mkdir crypto_lab/registry
cd source_code/tools/group_examplifier && make group_examplifier
cd ../subgroup_examplifier && make subgroup_examplifier
cd ../DH_KAP && make DH_KAP
cd ../cayley_table_generator && make cayley_table_generator
cd ../prime_table_generator && make prime_table_generator
echo "
Setup complete, you can now \"cd ./instruments/\" to start experimenting."
