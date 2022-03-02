#!/bin/bash

clear
rm -r applications/ 2> /dev/null;
if [ $? -eq 0 ];
then echo "removed 'applications/'";
else echo "DID NOT HAVE TO REMOVE 'applications/' (good)";
fi;

echo "continuing over at '__initialize_repository.sh'.
"; ./__initialize_repository.sh
