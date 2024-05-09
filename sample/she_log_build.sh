#!/bin/bash
GREEN='\033[32m'
RED='\033[31m'
RESET='\033[0m'
# project set
project="sample"
project_length=${#project}
# Get pwd string
path=$(pwd)
# Get last project_length chars
suffix="${path: -$project_length}"
if [ "$suffix" = "$project" ]; then
    echo -e "${GREEN}ok${RESET}"
else
    echo -e "${RED}Path error.Please ensure that the last few strings after using pwd are ${project}${RESET}"
    exit 1  # stop
fi

git clone https://github.com/shecannotsee/she_log
cd she_log
./scripts/third_party_she_test_build.sh
mkdir build
cd build
cmake ..
make -j8
make install
cd ..
cd ..
mv she_log she_log-src
mv -f she_log-src/build/she_log ./
rm -rf ./she_log-src
