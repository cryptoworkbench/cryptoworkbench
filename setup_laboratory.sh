#!/bin/bash 

mkdir laboratory/
mkdir registry/
cd source_code/project_code/group_examplifier && make group_examplifier
cd ../subgroup_examplifier && make subgroup_examplifier
cd ../dh_key_agreement && make dh_key_agreement
cd ../cayley_table_generator && make cayley_table_generator
cd ../prime_table_generator && make prime_table_generator
echo "Setup complete, \"cd laboratory/\" to enter the workbench environment."
