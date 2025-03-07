// header file for character struct
#include "menu.h"

#define HEART_WIDTH 15
#define HEART_HEIGHT 13

typedef struct {
  char* name;
  int pos_x;
  int pos_y;
} building;

typedef struct {
  unsigned char *sprite_facing_right_bytes;
  unsigned char *sprite_facing_left_bytes;
  unsigned char* sprite_facing_right_walking_bytes;
  unsigned char* sprite_facing_left_walking_bytes;
} character_bytes;

typedef struct {

} character_pixels;

typedef struct {

  character_bytes* byte_data;
  unsigned char* health_bar_values;
  unsigned char* weapon_1_values;
  rgb_value *sprite_facing_right_pixels;
  rgb_value *sprite_facing_left_pixels;
  rgb_value *sprite_facing_right_walking_pixels;
  rgb_value *sprite_facing_left_walking_pixels;
  rgb_value *health_bar;
  rgb_value * weapon_1;
  int width;
  int height;
  int pos_x;
  int fake_pos_x;
  int pos_y;
  int direction;
  int jumping;
  int jump_level;
  int moving_right;
  int moving_left;
  int health;
  int set_back_npc; //remove this variable at some point
  int hit_force;
  int is_in_enemy_collision;
} character;

typedef struct
{
    unsigned char *sprite_facing_right_bytes;
    rgb_value *sprite_facing_right_pixels;
    int width;
    int height;
    int pos_x;
    int pos_y;
    int jumping;
    int jump_level;
    int health;
} enemy;


typedef struct game_enterances
{
  building old_ladies_house;
  /* data */
};

