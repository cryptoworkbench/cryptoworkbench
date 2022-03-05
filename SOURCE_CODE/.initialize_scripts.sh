#!/bin/bash

___failed_builds=0
successfull_builds=0

cd scripts
    echo "Initializing scripts:   -->"
cd subgroup_examplifier_SCRIPT && make subgroup_examplifier_SCRIPT > /dev/null 2>> ../../../._script_initialization_errors
if [ $? -eq 0 ];
then echo "successfully initialized          'subgroup_examplifier.sh'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                                  'subgroup_examplifier.sh'         failed to initialize!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../

cd dh_key_agreement_SCRIPT && make dh_key_agreement_SCRIPT > /dev/null 2>> ../../../._script_initialization_errors
if [ $? -eq 0 ];
then echo "successfully initialized          'dh_key_agreement.sh'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                                  'dh_key_agreement.sh'         failed to initialize!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../

cd prime_factorize_SCRIPT && make prime_factorize_SCRIPT > /dev/null 2>> ../../../._script_initialization_errors
if [ $? -eq 0 ];
then echo "successfully initialized          'prime_factorize.sh'"; successfull_builds=$(( $successfull_builds + 1 ));
else echo "                                  'prime_factorize.sh'        failed to initialize!"; ___failed_builds=$((   $___failed_builds + 1 )); fi; cd ../

echo ""
echo " /==============================================================================\\"
echo " | $___failed_builds script(s) failed to initialize! $successfull_builds script(s) were successfully initialized. |"
echo " \\==============================================================================/"
