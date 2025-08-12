CC="gcc"

all: build

test:
	@echo "\033[34m[INFO]::Doing static analysis for TUI's\033[0m"
	cppcheck ./src/

build: test
	@echo "\033[34m[INFO]::Building all TUI's\033[0m"
	$(CC) -c src/command.c
	$(CC) -c src/teesh.c
	$(CC) -g -O0 -o teesh command.o teesh.o 

clean:
	@echo "\033[34m[INFO]::Cleaning build files\033[0m"
	rm -rf teesh.o command.o teesh
