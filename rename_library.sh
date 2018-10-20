#!/bin/bash
#
# Rename all occurances of CPPBOILERPLATE to a new value
#

if [ "$1" = "" ]; then
    echo "rename_library.sh NEWLIBRARYNAME"
    exit 1
fi

find src -type f -exec sed -i s/CPPBOILERPLATE/$1/g {} +
find include -type f -exec sed -i s/CPPBOILERPLATE/$1/g {} +
find test -type f -exec sed -i s/CPPBOILERPLATE/$1/g {} +
find .travis -type f -exec sed -i s/CPPBOILERPLATE/$1/g {} +
sed -i s/CPPBOILERPLATE/$1/g CMakeLists.txt
