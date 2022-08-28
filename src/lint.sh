#!/bin/bash

cp ../linters/CPPLINT.cfg .

find . -type f -name "*.cpp" | xargs python3 ../linters/cpplint.py --extensions=cpp
# find . -type f -name "*.h" | xargs python3 ../materials/linters/cpplint.py --extensions=c

#find . -type f -name "*.c" | xargs ~/homebrew/bin/cppcheck
#find . -type f -name "*.c" | xargs ~/homebrew/bin/cppcheck --enable=all --suppress=missingIncludeSystem
#find . -type f -name "*.c" | xargs cppcheck
find . -type f -name "*.cpp" | xargs cppcheck --enable=all --suppress=missingIncludeSystem

rm -f CPPLINT.cfg
