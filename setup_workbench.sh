#!/bin/bash 

mkdir workbench/
mkdir workbench/objects/
cd source_code/project_code/general_subgroup_generator && make general_subgroup_generator
cd ../../../source_code/project_code/cayley_table_generator && make cayley_table_generator
cd ../../../source_code/project_code/prime_table_generator && make prime_table_generator
