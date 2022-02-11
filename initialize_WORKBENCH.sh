#!/bin/bash 

mkdir WORKBENCH/
mkdir WORKBENCH/ARCHIVE
clear && echo "########### ASSEMBLY LINE ROLLING ! #######=====>"
cd SOURCE_CODE/TOOLS/equivalence_class && make equivalence_class && echo "#######===> The following tool has been assemblied/linked: additive_inverse
"
cd ../random_numbers && make random_numbers && echo "#######===> The following tool has been assemblied/linked: random_numbers
"
cd ../additive_inverse && make additive_inverse && echo "#######===> The following tool has been assemblied/linked: additive_inverse
"
cd ../modular_exponentiation && make modular_exponentiation && echo "#######===> The following tool has been assemblied/linked: modular_exponentiation
"
cd ../divide && make divide && echo "#######===> The following tool has been assemblied/linked: divide
"
cd ../multiplicative_inverse && make multiplicative_inverse && echo "#######===> The following tool has been assemblied/linked: multiplicative_inverse
"
cd ../greatest_common_divisor && make greatest_common_divisor && echo "#######===> The following tool has been assemblied/linked: greatest_common_divisor
"
cd ../least_common_multiple && make least_common_multiple && echo "#######===> The following tool has been assemblied/linked: least_common_multiple
"
cd ../group_operation && make group_operation && echo "#######===> The following tool has been assemblied/linked: group_operation
"
cd ../system_of_congruences && make system_of_congruences && echo "#######===> The following tool has been assemblied/linked: system_of_congruences
"
cd ../dh_key_agreement && make dh_key_agreement && echo "#######===> The following tool has been assemblied/linked: dh_key_agreement
"
echo "#######===> THE FOLLOWING BASIC TOOLS HAVE BEEN ASSEMBLED/LINKED: -->                         <===#######
~ equivalence_class
~ random numbers
~ additive_inverse
~ modular_exponentiation
~ finite_field_division
~ multiplicative_inverse
~ greatest_common_divisor
~ least_common_multiple
~ group_operation
~ system_of_congruences
~ dh_key_agreement
"
cd ../plot_polynomial && make plot_polynomial && echo "#######===> The following tool has been assemblied/linked: plot_polynomial
"
cd ../2_n_Shamir_Secret_Sharing && make 2_n_Shamir_Secret_Sharing && echo "#######===> The following tool has been assemblied/linked: 2_n_Shamir_Secret_Sharing
"
cd ../3_n_Shamir_Secret_Sharing && make 3_n_Shamir_Secret_Sharing && echo "#######===> The following tool has been assemblied/linked: 3_n_Shamir_Secret_Sharing
"
echo "#######===> SOME TOOLS FOR EXPLORING SHAMIR'S SECRET SHARING SCEME HAVE BEEN ASSEMBLED/LINKED: -->  <===#######
~ plot_polynomial
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
cd ../group_element_table_generator && make group_element_table_generator && echo "#######===> The following tool has been assemblied/linked: group_element_table_generator
"
cd ../subgroup_examplifier && make subgroup_examplifier && echo "#######===> The following tool has been assemblied/linked: subgroup_examplifier
"
echo "#######===> SOME MORE TOOLS HAVE BEEN ASSEMBLED/LINKED: -->                                         <===#######
~ sieve_of_eratosthenes
~ prime_table_exporter
~ factorize
~ modular_group_element_table_generator 
~ subgroup_examplifier
~ Diffie_Hellman_Key_Agreement
~ cayley_table_generator
"
# ALSO FIX THIS ONE!: cd ../Wipe_ARCHIVE && make Wipe_ARCHIVE && echo "#######===> The following tool has been assemblied/linked: Wipe_ARCHIVE
#"
cd ../View_LOGBOOK && make View_LOGBOOK && echo "#######===> The following tool has been assemblied/linked: View_LOGBOOK
"
echo "#######===> THE LABORATORY HOUSEHOLD EXECUTABLES HAVE BEEN ASSEMBLED/LINKED, NAMELY: -->             <===#######
~ Wipe_ARCHIVE
~ View_LOGBOOK
" # ^-- Notify end of last stage of compilation.

echo "########### ASSEMBLY LINE HALTED !
########### The setup completed ! (presumably)
#############################################################################
####### 'cd WORKBENCH/' to enter your VIRTUAL MATHEMATICS LABORATORY. #######"
# ls WORKBENCH/ | wc -l FOR SOME REASON DOESN'T WORK
# ^-- Bash script done
