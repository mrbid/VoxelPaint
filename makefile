all:
	mkdir -p release

	gcc -DNO_COMPRESSION main.c -Ofast -lm -lSDL2 -lGLESv2 -lEGL -o release/vox
	strip --strip-unneeded release/vox
	upx --lzma --best release/vox

	gcc main.c -Ofast -lm -lz -lSDL2 -lGLESv2 -lEGL -o release/vox_compressed
	strip --strip-unneeded release/vox_compressed
	upx --lzma --best release/vox_compressed

	gcc -DNO_COMPRESSION -DSKYBLUE main.c -Ofast -lm -lSDL2 -lGLESv2 -lEGL -o release/voxsky
	strip --strip-unneeded release/voxsky
	upx --lzma --best release/voxsky

	gcc -DSKYBLUE main.c -Ofast -lm -lz -lSDL2 -lGLESv2 -lEGL -o release/voxsky_compressed
	strip --strip-unneeded release/voxsky_compressed
	upx --lzma --best release/voxsky_compressed

test:
	gcc main.c -Ofast -lm -lz -lSDL2 -lGLESv2 -lEGL -o vox_test
	./vox_test
	rm vox_test

clean:
	rm -r release
