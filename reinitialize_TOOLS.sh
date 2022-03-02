#!/bin/bash

clear
rm -r TOOLS/ 2> /dev/null;
if [ $? -eq 0 ];
then echo "Removed 'TOOLS/'";
else echo "Did not have to remove 'TOOLS/'";
# else echo "Did not have to remove 'TOOLS/', it seems like somoone already removed it, or you must be initializing using this reinitialization script (nothing wrong with that!).
# "
fi;

echo "Continue in '__initialize_TOOLS.sh' ...
"; ./__initialize_TOOLS.sh

#echo "Handing over control to '__initialize_TOOLS.sh'		(a.k.a. continuing over at '__initialize_TOOLS.sh')
#"; ./__initialize_TOOLS.sh
