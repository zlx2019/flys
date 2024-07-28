# CMake 编译
all:
	cmake -S . -B  ./build
	make -C ./build
	./build/bin/flys

clean:
	rm -rf ./build