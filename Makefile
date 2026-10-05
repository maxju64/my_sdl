build: src/main.c src/utils.c
	gcc src/main.c `pkgconf --cflags sdl3` `pkgconf --libs sdl3` src/utils.c -o ./build/frame -lm

run:
	./build/frame
