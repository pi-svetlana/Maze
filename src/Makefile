.PHONY: tests
build:
	cmake -S ./ -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS_DEBUG="-g -fprofile-arcs -ftest-coverage -std=c++17"
	cmake --build build

rebuild: uninstall clean build

uninstall:
	rm -rf build

run:
	open build/maze/maze.app

tests:
	cd build/tests ; ./tests

clean:
	rm -rf *user */*/*.gch