all:
	mkdir -p build
	gcc -lreadline src/*.c -o build/letra
run:
	mkdir -p build
	gcc -lreadline src/*.c -o build/letra
	build/letra
debug:
	mkdir -p build
	gcc -g -lreadline src/*.c -o build/letra
	gdb build/letra
test:
	mkdir -p build
	gcc -lreadline src/*.c -o build/letra
	build/letra file.txt.bak
