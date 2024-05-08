#!/bin/bash
GREEN='\033[32m'
RED='\033[31m'
RESET='\033[0m'
# project set
project="she_log"
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

cd third_party
git clone https://github.com/shecannotsee/she_test.git
mv she_test she_test-src
cd she_test-src
cmake -B build
cmake --build build -j8
cmake --build build --target install
mv -f ./build/she_test ../
cd ..
rm -rf ./she_test-src
