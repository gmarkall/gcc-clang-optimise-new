all:
	g++ -std=c++14 -O3 test.cpp -c -o test-gcc.o
	g++ -std=c++14 -O3 override.cpp -c -o override-gcc.o
	g++ test-gcc.o override-gcc.o -o gcc-test
	g++ -std=c++14 -O3 test2.cpp -c -o test2-gcc.o
	g++ test2-gcc.o override-gcc.o -o gcc-test2
	clang++ -O3 test.cpp -c -o test-clang.o
	clang++ -O3 override.cpp -c -o override-clang.o
	clang++ test-clang.o override-clang.o -o clang-test
	clang++ -std=c++14 -O3 test2.cpp -c -o test2-clang.o
	clang++ test2-clang.o override-clang.o -o clang-test2

clean:
	rm -f *.o gcc-test clang-test gcc-test2 clang-test2
