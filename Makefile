# Cmake 编译
all:
	cmake -S . -B ./target
	make -C ./target