set -e

mkdir -p build/
cd build/

# cmake -D "CMAKE_C_FLAGS=-Wall"  ..
cmake -D CMAKE_C_COMPILER=clang -D "CMAKE_C_FLAGS=-g -Wall -Wpedantic -Wextra -Wno-unreachable-code  -Wno-unused-function" ..
# cmake -D "CMAKE_C_FLAGS=-pedantic -Wno-unreachable-code -Wno-unused-function" ..
cmake --build .

./algo_test
