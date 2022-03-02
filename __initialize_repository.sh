#!/bin/bash

mkdir applications/; echo "Created directory 'applications/'"
mkdir applications/ARCHIVE; echo "Created directory 'applications/ARCHIVE'"

cd SOURCE_CODE/
echo ""; ./.initialize_applications.sh;
echo ""; ./.initialize_scripts.sh
