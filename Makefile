all:
	cmake -S . -B ./target
	make -C ./target
	./target/bin/main