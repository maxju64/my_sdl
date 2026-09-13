build: src/main.c
	gcc src/main.c `pkgconf --cflags sdl3` `pkgconf --libs sdl3` -o ./build/frame

run:
	./build/frame
