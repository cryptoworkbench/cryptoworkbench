#!/bin/bash

successfull_builds=0
___failed_builds=0
cd applications
echo "Building applications:        -->"
cd 2_n_Shamir_Secret_Sharing && make 2_n_Shamir_Secret_Sharing > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    '2_n_Shamir_Secret_Sharing'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    '2_n_Shamir_Secret_Sharing'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 0 )); fi; cd ..

cd 3_n_Shamir_Secret_Sharing && make 3_n_Shamir_Secret_Sharing > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    '3_n_Shamir_Secret_Sharing'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    '3_n_Shamir_Secret_Sharing'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd additive_inverse && make additive_inverse > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'additive_inverse'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'additive_inverse'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd dh_key_agreement && make dh_key_agreement > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'dh_key_agreement'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'dh_key_agreement'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd divide && make divide > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'divide'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'divide'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd equivalence_class && make equivalence_class > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'equivalence_class'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'equivalence_class'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd factorization_based_primality_test && make factorization_based_primality_test > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'factorization_based_primality_test'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'factorization_based_primality_test'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd factorize && make factorize > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'factorize'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'factorize'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd greatest_common_divisor && make greatest_common_divisor > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'greatest_common_divisor'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'greatest_common_divisor'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd group_element_exporter && make group_element_exporter > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'group_element_exporter'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'group_element_exporter'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd group_operation && make group_operation > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'group_operation'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'group_operation'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd jacobi_symbol && make jacobi_symbol > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'jacobi_symbol'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'jacobi_symbol'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd least_common_multiple && make least_common_multiple > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'least_common_multiple'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'least_common_multiple'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd modular_exponentiation && make modular_exponentiation > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'modular_exponentiation'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'modular_exponentiation'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd multiplicative_inverse && make multiplicative_inverse > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'multiplicative_inverse'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'multiplicative_inverse'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd plot_polynomial && make plot_polynomial > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'plot_polynomial'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'plot_polynomial'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd prime_factorize && make prime_factorize > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'prime_factorize'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'prime_factorize'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd prime_table_exporter && make prime_table_exporter > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'prime_table_exporter'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'prime_table_exporter'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd quadratic_residue && make quadratic_residue > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'quadratic_residue'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'quadratic_residue'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd random_numbers && make random_numbers > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'random_numbers'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'random_numbers'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd sieve_of_eratosthenes && make sieve_of_eratosthenes > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'sieve_of_eratosthenes'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'sieve_of_eratosthenes'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd subgroup_examplifier && make subgroup_examplifier > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'subgroup_examplifier'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'subgroup_examplifier'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd system_of_congruences && make system_of_congruences > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'system_of_congruences'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'system_of_congruences'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd View_LOGBOOK && make View_LOGBOOK > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'View_LOGBOOK'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'View_LOGBOOK'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd Wipe_ARCHIVE && make Wipe_ARCHIVE > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'Wipe_ARCHIVE'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'Wipe_ARCHIVE'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

cd Wipe_LOGBOOK && make Wipe_LOGBOOK > /dev/null 2>> ../../../.initialization_errors.regarding_application_builds
if [ $? -eq 0 ];
then echo "successfully build application    'Wipe_LOGBOOK'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                   application    'Wipe_LOGBOOK'         FAILED TO BUILD!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ..

echo "";
echo " /==============================================================================\\"
echo " | $___failed_builds APPLICATION(S) FAILED TO BUILD! $successfull_builds application(s) were successfully build. |"
echo " \\==============================================================================/";
