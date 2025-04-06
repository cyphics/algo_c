set -e

mkdir -p build/
cd build/

cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 \
	  -DCMAKE_C_COMPILER=clang \
	  -DCMAKE_C_FLAGS="-O0 -g -gdwarf-4 -Wall -Wpedantic -Wextra -Wno-unreachable-code  -Wno-unused-function -fstack-protector -fno-omit-frame-pointer" ..
cmake --build . --parallel 

ctest  || {
  echo ""
  # echo "Tests failed! Running gdb on the test binary..."
  # gdb -ex "run" -ex "bt full" ./build/test/UnitTests
}
