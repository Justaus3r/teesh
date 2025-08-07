CC="gcc"

all: build


build:
	@echo "Building all TUI's"
	$(CC) -c src/command.c
	$(CC) -c src/teesh.c
	$(CC) -g -o teesh command.o teesh.o 

clean:
	@echo "Cleaning build files"
	rm -rf teesh.o command.o teesh
