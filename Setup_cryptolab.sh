#!/bin/bash 

mkdir crypto_lab/
mkdir crypto_lab/tools
mkdir crypto_lab/registry

cd source_code/tools/group_examplifier && make group_examplifier && echo "### SUCCESSFULLY BUILD THE TOOL \"group_examplifier\".
"
cd ../subgroup_examplifier && make subgroup_examplifier && echo "### SUCCESSFULLY BUILD THE TOOL \"subgroup_examplifier\".
"
cd ../Diffie_Hellman_Key_Agreement && make Diffie_Hellman_Key_Agreement && echo "### SUCCESSFULLY BUILD THE TOOL \"Diffie_Hellman_Key_Agreement\".
"
cd ../cayley_table_generator && make cayley_table_generator && echo "### SUCCESSFULLY BUILD THE TOOL \"cayley_table_generator\".
"
cd ../prime_table_generator && make prime_table_generator && echo "### SUCCESSFULLY BUILD THE TOOL \"prime_table_generator\".
"
cd ../modular_exponentiation && make modular_exponentiation && echo "### SUCCESSFULLY BUILD THE TOOL \"modular_exponentiation\".
"
cd ../CLEAR_LABORATORY_LOGBOOK && make CLEAR_LABORATORY_LOGBOOK && echo "### SUCCESSFULLY BUILD THE TOOL \"CLEAR_LABORATORY_LOGBOOK\".
"
cd ../CLEAR_REGISTRY && make CLEAR_REGISTRY && echo "### SUCCESSFULLY BUILD THE TOOL \"CLEAR_REGISTRY\".

"
echo "Run from $(cd ../../../ && pwd) the following if you wish to start over:
\"rm -fR crytpo_lab/ && ./Setup_cryptolab.sh\"

Setup complete, you can now \"cd crypto_lab/tools/\" to start experimenting."
