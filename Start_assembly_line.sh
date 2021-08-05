#!/bin/bash 
mkdir crypto_lab/
mkdir crypto_lab/tools
mkdir crypto_lab/REGISTRY
clear && echo "########### ASSEMBLY LINE ROLLING ! #######=====>"
cd source_code/tools/group_exporter && make group_exporter && echo "#######===> The following instrument has been assemblied/linked: group_exporter
"
cd ../subgroup_examplifier && make subgroup_examplifier && echo "#######===> The following instrument has been assemblied/linked: subgroup_examplifier
"
cd ../Diffie_Hellman_Key_Agreement && make Diffie_Hellman_Key_Agreement && echo "#######===> The following instrument has been assemblied/linked: Diffie_Hellman_Key_Agreement
"
cd ../cayley_table_generator && make cayley_table_generator && echo "#######===> The following instrument has been assemblied/linked: cayley_table_generator
"
cd ../prime_table_generator && make prime_table_generator && echo "#######===> The following instrument has been assemblied/linked: prime_table_generator
"
cd ../modular_exponentiation && make modular_exponentiation && echo "#######===> The following instrument has been assemblied/linked: modular_exponentiation
"
cd ../REGISTRY_erase && make REGISTRY_erase && echo "#######===> The following instrument has been assemblied/linked: REGISTRY_erase
"
cd ../VIEW_laboratory_LOGBOOK && make VIEW_laboratory_LOGBOOK && echo "#######===> The following instrument has been assemblied/linked: VIEW_laboratory_LOGBOOK
"
cd ../LOGBOOK_erase && make LOGBOOK_erase && echo "#######===> The following instrument has been assemblied/linked: LOGBOOK_erase
"
echo "########### ASSEMBLY LINE HALTED !
########### The setup completed ! (presumably)
#####################################################################################################
####### 'ls crypto_lab/tools/' to see what instruments fell from the assembly line.           #######
####### 'cd crypto_lab/tools/' to enter your very own VIRTUAL MATHEMATICS fucking LABORATORY. #######"
