#!/bin/bash 

mkdir WORKBENCH/
mkdir WORKBENCH/INSTRUMENTS
mkdir WORKBENCH/ARCHIVE
clear && echo "########### ASSEMBLY LINE ROLLING ! #######=====>"
cd SOURCE_CODE/INSTRUMENTS/element_exporter && make element_exporter && echo "#######===> The following instrument has been assemblied/linked: element_exporter
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
################################################################################################
####### 'ls WORKBENCH/INSTRUMENTS/' to see what instruments fell from the assembly line. #######
####### 'cd WORKBENCH/INSTRUMENTS/' to enter your VIRTUAL MATHEMATICS LABORATORY.        #######"
