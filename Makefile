all:
	g++ -std=c++14 -O3 test.cpp -c -o test-gcc.o
	g++ -std=c++14 -O3 override.cpp -c -o override-gcc.o
	g++ test-gcc.o override-gcc.o -o gcc-test
	clang++ -O3 test.cpp -c -o test-clang.o
	clang++ -O3 override.cpp -c -o override-clang.o
	clang++ test-clang.o override-clang.o -o clang-test

clean:
	rm -f *.o gcc-test clang-test
