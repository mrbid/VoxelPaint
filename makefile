all:
	gcc main.c -Ofast -lm -lSDL2 -lGLESv2 -lEGL -o vox
	strip --strip-unneeded vox
	upx --lzma --best vox

run: all
	./vox
