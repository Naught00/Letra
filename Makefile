all:
	mkdir -p build
	gcc -lreadline src/*.c -o build/abre
