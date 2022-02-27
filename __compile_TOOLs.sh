#!/bin/bash

clear
mkdir WORKBENCH/; echo "Created directory 'WORKBENCH/'"
mkdir WORKBENCH/ARCHIVE; echo "Created directory 'WORKBENCH/ARCHIVE'"

cd SOURCE_CODE/TOOLS

successfull_builds=0
___failed_builds=0
echo ""
echo "COMPILING THE TOOLs: -->"
cd 2_n_Shamir_Secret_Sharing && make 2_n_Shamir_Secret_Sharing > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled '2_n_Shamir_Secret_Sharing'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      '2_n_Shamir_Secret_Sharing' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd 3_n_Shamir_Secret_Sharing && make 3_n_Shamir_Secret_Sharing > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled '3_n_Shamir_Secret_Sharing'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      '3_n_Shamir_Secret_Sharing' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd additive_inverse && make additive_inverse > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'additive_inverse'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'additive_inverse' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd dh_key_agreement && make dh_key_agreement > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'dh_key_agreement'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'dh_key_agreement' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd divide && make divide > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'divide'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'divide' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd equivalence_class && make equivalence_class > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'equivalence_class'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'equivalence_class' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd factorization_based_primality_test && make factorization_based_primality_test > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'factorization_based_primality_test'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'factorization_based_primality_test' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd factorize && make factorize > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'factorize'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'factorize' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd greatest_common_divisor && make greatest_common_divisor > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'greatest_common_divisor'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'greatest_common_divisor' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd group_element_exporter && make group_element_exporter > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'group_element_exporter'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'group_element_exporter' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd group_operation && make group_operation > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'group_operation'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'group_operation' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd jacobi_symbol && make jacobi_symbol > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'jacobi_symbol'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'jacobi_symbol' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd least_common_multiple && make least_common_multiple > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'least_common_multiple'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'least_common_multiple' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd modular_exponentiation && make modular_exponentiation > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'modular_exponentiation'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'modular_exponentiation' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd multiplicative_inverse && make multiplicative_inverse > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'multiplicative_inverse'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'multiplicative_inverse' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd plot_polynomial && make plot_polynomial > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'plot_polynomial'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'plot_polynomial' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd prime_factorize && make prime_factorize > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'prime_factorize'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'prime_factorize' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd prime_table_exporter && make prime_table_exporter > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'prime_table_exporter'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'prime_table_exporter' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd quadratic_residue && make quadratic_residue > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'quadratic_residue'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'quadratic_residue' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd random_numbers && make random_numbers > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'random_numbers'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'random_numbers' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd sieve_of_eratosthenes && make sieve_of_eratosthenes > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'sieve_of_eratosthenes'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'sieve_of_eratosthenes' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd subgroup_examplifier && make subgroup_examplifier > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'subgroup_examplifier'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'subgroup_examplifier' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd system_of_congruences && make system_of_congruences > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'system_of_congruences'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'system_of_congruences' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd View_LOGBOOK && make View_LOGBOOK > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'View_LOGBOOK'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'View_LOGBOOK' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd Wipe_ARCHIVE && make Wipe_ARCHIVE > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'Wipe_ARCHIVE'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'Wipe_ARCHIVE' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../
cd Wipe_LOGBOOK && make Wipe_LOGBOOK > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ]; then echo "Successfully compiled 'Wipe_LOGBOOK'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                      'Wipe_LOGBOOK' FAILED TO COMPILE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../

echo ""
echo "==================================================================\\"
echo "| $___failed_builds TOOLS FAILED TO COMPILE! $successfull_builds tools were successfully compiled. |"
echo "==================================================================/"

___failed_builds=0
successfull_builds=0
echo ""; echo ""; echo "COPYING THE SCRIPTS: -->"
cd subgroup_examplifier_SCRIPT && make subgroup_examplifier_SCRIPT > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ];
then echo "Successfully copied 'subgroup_examplifier.sh'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                    'subgroup_examplifier.sh' COPY FAILURE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../

cd dh_key_agreement_SCRIPT && make dh_key_agreement_SCRIPT > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ];
then echo "Successfully copied 'dh_key_agreement.sh'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                    'dh_key_agreement.sh' COPY FAILURE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../

cd prime_factorize_SCRIPT && make prime_factorize_SCRIPT > /dev/null 2>> ../../../initialization_errors
if [ $? -eq 0 ];
then echo "Successfully copied 'prime_factorize.sh'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                    'prime_factorize.sh' COPY FAILURE!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../

echo ""
echo "=======================================================================\\"
echo "| Failed to install $___failed_builds scripts ! $successfull_builds scripts were successfully installed. |"
echo "=======================================================================/"
