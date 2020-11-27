all: clean build
debug: clean debug-build

clean:
	rm stackProgram

build:
	gcc stackProgram.c stack.c hello.c -o stackProgram -std=c89 -Wall -pedantic

debug-build:
	gcc stackProgram.c stack.c hello.c -o stackProgram -std=c89 -Wall -pedantic -g
