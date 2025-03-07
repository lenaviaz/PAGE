#include "../mapGenerator.h"
#include <SDL.h>
#include <png.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <zlib.h>


#define FALSE 0
#define TRUE 1
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define RENDER_SCALE 200 
#define CHARACTER_LOCK_POINT 100
#define NUM_RGB_VALUES_IN_PIXEL 3
#define NUM_POINTS_IN_RGB 3
#define MAX_JUMP 40
#define LOCK_SCREENPOINT 100

// temporarily hard coded
#define BACKGROUND_WIDTH 400

#define PLAYER_WIDTH 10
#define PLAYER_HEIGHT 16

#define RIGHT 1
#define LEFT -1

typedef struct {
  unsigned char *byte_values;
  rgb_value *pixels;
  int width;
  int height;
} background_image;

typedef struct {
  int x;
  int y;
  int width;
  int height;

} camera_coordinates;

void write_ppm_data(char *ppm_file, char *textfile);
