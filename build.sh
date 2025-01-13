set -e

mkdir -p build/
cd build/

cmake ..
cmake --build .

./algo_test
