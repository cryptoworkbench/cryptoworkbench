# sort using ls -'Xla' to sort alphabetically on the error file's extension
#!/bin/bash

mkdir applications/ > /dev/null 2>> .initialization_errors.regarding_mkdir; if [ $? -eq 0 ]; then echo "Created target directory 'applications/'"; else echo "Target directory 'applications' already existed!"; fi
mkdir applications/ARCHIVE > /dev/null 2>> .initialization_errors.regarding_mkdir; if [ $? -eq 0 ]; then echo "Created target directory 'applications/ARCHIVE'"; else echo "Target directory 'applications/ARCHIVE' already existed!"; fi

cd SOURCE_CODE/
echo ""; ./.initialize_applications.sh;
echo ""; ./.initialize_scripts.sh
