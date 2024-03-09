
all: bin/maze

.PHONY: all test clean

bin/maze: $(wildcard src/*.c) | bin
	gcc -Wall -ggdb --pedantic src/*.c -o bin/maze

bin:
	mkdir -p bin

clean:
	rm -rf bin

test: all
	bin/maze
