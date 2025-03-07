#include "character.h"

void fill_byte_and_pixel_data(character* ch, char* character_sprite_ppm, character* sprite_txt, unsigned char *sprite_bytes);

character* generateCharacter(
	             char* character_sprite_1_ppm,
			     char* character_sprite_1_txt,
	             char* character_sprite_2_ppm,
                 char* character_sprite_2_txt,
				 char* character_sprite_3_ppm,
				 char* character_sprite_3_txt,
				 char* character_sprite_4_ppm,
				 char* character_sprite_4_txt,
			     int start_x,
			     int start_y,
				 char* heart_ppm,
				 char* heart_txt);

enemy* generateEnemy(char *enemy_sprite_1_ppm, char *enemy_sprite_1_txt);

void free_enemy(enemy* en);

background_image* generateBackground(char* background_pixel_ppm, char* background_pixel_textfile);

void free_character(character* ch);

void free_background(background_image* background);

int get_draw_pos_x(character* ch);

void draw_to_screen(SDL_Renderer *renderer, character* ch);

void draw_enemy_to_screen(SDL_Renderer *renderer, int** collision_map, enemy* en, character* ch, int frame_left_val);

void draw_health_to_screen(SDL_Renderer *renderer, int** collision_map, character* ch);

int** create2DCollisionMapArray(char* map_file, int width, int height);

character_fell_out_of_bounds(character* ch);

void free2DCollisionMapArray(int** collision_array, int height);

int collision_detected(character* ch, int** collision_map);

int check_enemy_collision(character* ch, enemy* en, int is_jumping);

void draw_collision_to_screen(SDL_Renderer *renderer, int** collision_map, character* ch);

int is_front_collision(character* ch, int** collision_map);

void update_player_position(character* ch, int** collision_map, int force);

update_enemy_position(enemy* en);

int is_new_scene_enterance(character* ch, int** collision_map);

void key_press_right(character* ch);

void key_press_left(character* ch);

void key_press_space(character* ch);

void key_press_down(character* ch);

void key_release_right(character* ch);

void key_release_left(character* ch);

void key_release_space(character* ch);

camera_coordinates update_viewpoint_coordinates(character* ch);

 
