all:
	mkdir -p build
	gcc -lreadline src/*.c -o build/abre
run:
	mkdir -p build
	gcc -lreadline src/*.c -o build/abre
	build/abre
debug:
	mkdir -p build
	gcc -g -lreadline src/*.c -o build/abre
	gdb build/abre
test:
	mkdir -p build
	gcc -lreadline src/*.c -o build/abre
	build/abre file.txt.bak
