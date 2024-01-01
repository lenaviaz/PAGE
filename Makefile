
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -fsanitize=address -static-libasan -I. -I./include
SOURCES := $(shell find $(src) -name '*.c')

TARGET = game

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image