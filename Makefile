CC = g++
CFLAGS = -Isrc/include/SDL2
LDFLAGS = -Lsrc/include/SDL2 -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image
SOURCES = main.cpp game.cpp render.cpp tetromino.cpp utils.cpp
TARGET = main.exe

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)
clean:
	del $(TARGET)
