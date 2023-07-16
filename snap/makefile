all:
	gcc -DNO_COMPRESSION ../main.c -Ofast -lm -lSDL2 -lGLESv2 -lEGL -o voxelpaint

install:
	cp voxelpaint $(DESTDIR)

uninstall:
	rm $(DESTDIR)/voxelpaint

clean:
	rm voxelpaint
