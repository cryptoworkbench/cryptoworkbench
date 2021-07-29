#!/bin/bash 

mkdir crypto_lab/
mkdir crypto_lab/tools
mkdir crypto_lab/registry
cd source_code/tools/group_examplifier && make group_examplifier && echo "SUCCESSFULLY MADE APPLICATION \"group_examplifier\"
"
cd ../subgroup_examplifier && make subgroup_examplifier && echo "SUCCESSFULLY MADE APPLICATION \"subgroup_examplifier\"
"
cd ../Diffie_Hellman_Key_Agreement && make Diffie_Hellman_Key_Agreement && echo "SUCCESSFULLY MADE APPLICATION \"Diffie_Hellman_Key_Agreement\"
"
cd ../cayley_table_generator && make cayley_table_generator && echo "SUCCESSFULLY MADE APPLICATION \"cayley_table_generator\"
"
cd ../prime_table_generator && make prime_table_generator && echo "SUCCESSFULLY MADE APPLICATION \"prime_table_generator\"
"
cd ../modular_exponentiation && make modular_exponentiation && echo "SUCCESSFULLY MADE APPLICATION \"modular_exponentiation\"
"
cd ../EMPTY_LABORATORY_LOGBOOK && make EMPTY_LABORATORY_LOGBOOK && echo "SUCCESSFULLY MADE APPLICATION \"EMPTY_LABORATORY_LOGBOOK\""
echo "Run from $(cd ../../../ && pwd) the following if you wish to start over:
\"rm -fR crytpo_lab/ && ./Setup_cryptolab.sh\"

Setup complete, you can now \"cd crypto_lab/tools/\" to start experimenting."
