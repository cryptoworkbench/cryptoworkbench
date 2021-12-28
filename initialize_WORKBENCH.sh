#!/bin/bash 

mkdir WORKBENCH/
mkdir WORKBENCH/ARCHIVE
clear && echo "########### ASSEMBLY LINE ROLLING ! #######=====>"
cd SOURCE_CODE/INSTRUMENTS/modular_group_element_table_generator && make modular_group_element_table_generator && echo "#######===> The following instrument has been assemblied/linked: modular_group_element_table_generator
"
cd ../subgroup_examplifier && make subgroup_examplifier && echo "#######===> The following instrument has been assemblied/linked: subgroup_examplifier
"
cd ../3_n_Shamir_Secret_Sharing_Sceme_PROOF_OF_CONCEPT && make 3_n_Shamir_Secret_Sharing_Sceme_PROOF_OF_CONCEPT && echo "#######===> The following proof of concept application has been assembled: 3_n_Shamir_Secret_Sharing_Sceme_PROOF_OF_CONCEPT
"
cd ../Diffie_Hellman_Key_Agreement && make Diffie_Hellman_Key_Agreement && echo "#######===> The following instrument has been assemblied/linked: Diffie_Hellman_Key_Agreement
"
cd ../cayley_table_generator && make cayley_table_generator && echo "#######===> The following instrument has been assemblied/linked: cayley_table_generator
"
# cd ../prime_table_generator && make prime_table_generator && echo "#######===> The following instrument has been assemblied/linked: prime_table_generator
#"
cd ../modular_exponentiation && make modular_exponentiation && echo "#######===> The following instrument has been assemblied/linked: modular_exponentiation
"
cd ../Wipe_ARCHIVE && make Wipe_ARCHIVE && echo "#######===> The following instrument has been assemblied/linked: Wipe_ARCHIVE
"
cd ../View_LOGBOOK && make View_LOGBOOK && echo "#######===> The following instrument has been assemblied/linked: View_LOGBOOK
"
cd ../Wipe_LOGBOOK && make Wipe_LOGBOOK && echo "#######===> The following instrument has been assemblied/linked: Wipe_LOGBOOK
"
echo "########### ASSEMBLY LINE HALTED !
########### The setup completed ! (presumably)
#############################################################################
####### 'cd WORKBENCH/' to enter your VIRTUAL MATHEMATICS LABORATORY. #######"
