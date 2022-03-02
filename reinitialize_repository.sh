#!/bin/bash

clear
rm -r applications/ 2> /dev/null;
if [ $? -eq 0 ];
then echo "Removed 'applications/'";
else echo "Did not have to remove 'applications/'";
# else echo "Did not have to remove 'applications/', it seems like somoone already removed it, or you must be initializing using this reinitialization script (nothing wrong with that!).
# "
fi;

echo "Continue in '__initialize_repository.sh' ...
"; ./__initialize_repository.sh

#echo "Handing over control to '__initialize_repository.sh'		(a.k.a. continuing over at '__initialize_repository.sh')
#"; ./__initialize_repository.sh
