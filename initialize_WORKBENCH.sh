#!/bin/bash 

mkdir WORKBENCH/
mkdir WORKBENCH/ARCHIVE
clear && echo "########### ASSEMBLY LINE ROLLING ! #######=====>"
cd SOURCE_CODE/TOOLS/additive_inverse && make additive_inverse && echo "#######===> The following tool has been assemblied/linked: additive_inverse
"
cd ../modular_exponentiation && make modular_exponentiation && echo "#######===> The following tool has been assemblied/linked: modular_exponentiation
"
cd ../finite_field_division && make finite_field_division && echo "#######===> The following tool has been assemblied/linked: finite_field_division
" # ^-- The tool 'finite_field_division' is a dependency of 'multiplicative_inverse' -->
cd ../multiplicative_inverse && make multiplicative_inverse && echo "#######===> The following tool has been assemblied/linked: multiplicative_inverse
"
echo "#######===> THE FOLLOWING BASIC TOOLS HAVE BEEN ASSEMBLED/LINKED: -->                         <===#######
~ additive_inverse
~ modular_exponentiation
~ finite_field_division
~ multiplicative_inverse
" # ^-- Notify end of first stage of compilation.

cd ../polynomial_function_over_a_GF && make polynomial_function_over_a_GF && echo "#######===> The following tool has been assemblied/linked: polynomial_function_over_a_GF
"
cd ../2_n_Shamir_Secret_Sharing && make 2_n_Shamir_Secret_Sharing && echo "#######===> The following tool has been assemblied/linked: 2_n_Shamir_Secret_Sharing
"
cd ../3_n_Shamir_Secret_Sharing && make 3_n_Shamir_Secret_Sharing && echo "#######===> The following tool has been assemblied/linked: 3_n_Shamir_Secret_Sharing
"
echo "#######===> SOME TOOLS FOR EXPLORING SHAMIR'S SECRET SHARING SCEME HAVE BEEN ASSEMBLED/LINKED: -->  <===#######
~ polynomial_function_over_a_GF
~ 2_n_Shamir_Secret_Sharing
~ 3_n_Shamir_Secret_Sharing
" # ^-- Notify end of second stage of compilation.

cd ../sieve_of_eratosthenes && make sieve_of_eratosthenes && echo "#######===> The following tool has been assemblied/linked: sieve_of_eratosthenes
"
cd ../prime_table_exporter && make prime_table_exporter && echo "#######===> The following tool has been assemblied/linked: prime_table_exporter
"
cd ../factorize && make factorize && echo "#######===> The following tool has been assemblied/linked: factorize
"
cd ../factorization_based_primality_test && make factorization_based_primality_test && echo "#######===> The following tool has been assemblied/linked: factorization_based_primality_test
"
cd ../modular_group_element_table_generator && make modular_group_element_table_generator && echo "#######===> The following tool has been assemblied/linked: modular_group_element_table_generator
"
# FIX THIS ONE!!!: cd ../subgroup_examplifier && make subgroup_examplifier && echo "#######===> The following tool has been assemblied/linked: subgroup_examplifier
#"
# cd ../Diffie_Hellman_Key_Agreement && make Diffie_Hellman_Key_Agreement && echo "#######===> The following tool has been assemblied/linked: Diffie_Hellman_Key_Agreement
#"
# cd ../cayley_table_generator && make cayley_table_generator && echo "#######===> The following tool has been assemblied/linked: cayley_table_generator
#"
echo "#######===> SOME MORE TOOLS HAVE BEEN ASSEMBLED/LINKED: -->                                         <===#######
~ sieve_of_eratosthenes
~ prime_table_exporter
~ factorize
~ modular_group_element_table_generator 
~ subgroup_examplifier
~ Diffie_Hellman_Key_Agreement
~ cayley_table_generator
" # ^-- Notify end of third stage of compilation.

cd ../Wipe_ARCHIVE && make Wipe_ARCHIVE && echo "#######===> The following tool has been assemblied/linked: Wipe_ARCHIVE
"
cd ../View_LOGBOOK && make View_LOGBOOK && echo "#######===> The following tool has been assemblied/linked: View_LOGBOOK
"
echo "#######===> THE LABORATORY HOUSEHOLD EXECUTABLES HAVE BEEN ASSEMBLED/LINKED, NAMELY: -->             <===#######
~ Wipe_ARCHIVE
~ View_LOGBOOK
~ Wipe_LOGBOOK
" # ^-- Notify end of last stage of compilation.

echo "########### ASSEMBLY LINE HALTED !
########### The setup completed ! (presumably)
#############################################################################
####### 'cd WORKBENCH/' to enter your VIRTUAL MATHEMATICS LABORATORY. #######"
# ^-- Bash script done
