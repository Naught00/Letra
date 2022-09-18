all:
	mkdir -p build
	gcc -lreadline src/*.c -o build/abre
run:
	mkdir -p build
	gcc -lreadline src/*.c -o build/abre
	build/abre
