set -e

mkdir -p build/
cd build/

# cmake -D "CMAKE_C_FLAGS=-Wall"  ..
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -D CMAKE_C_COMPILER=clang -D "CMAKE_C_FLAGS=-g -Wall -Wpedantic -Wextra -Wno-unreachable-code  -Wno-unused-function -fno-stack-protector" ..
# cmake -D "CMAKE_C_FLAGS=-pedantic -Wno-unreachable-code -Wno-unused-function" ..
cmake --build .

./algo_test
