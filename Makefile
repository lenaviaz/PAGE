# Easy sample Makefile

CC = gcc

# Compiler flags
CFLAGS = -g -Wall -fsanitize=address -static-libasan -I. -I./include

TARGET = hellomake

$(TARGET): src/main.c src/core.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c src/core.c src/menu.c src/game_objects.c -L. -lmapGenerator -Wl,-rpath,$(PWD) `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image
