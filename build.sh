mkdir -p build/
cd build/

make ..
cmake --build .

./algo_test
