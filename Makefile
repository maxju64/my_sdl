build:
	gcc main.c `pkgconf --cflags sdl3` `pkgconf --libs sdl3` -o frame

run:
	./frame
