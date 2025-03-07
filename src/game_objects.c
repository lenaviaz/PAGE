#include "../include/game_objects.h"

character* generateCharacter(char* character_sprite_1_ppm, 
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
                             char* heart_txt)
{

  /* get dimention data */
  dimensions player_dims = getDimensions(character_sprite_1_ppm);
  int buffer_size = player_dims.width * player_dims.height * NUM_RGB_VALUES_IN_PIXEL * NUM_POINTS_IN_RGB;

  /*  */
  character *ch = (character *)malloc(sizeof(character));
  //malloc byte data
  ch->byte_data = (character_bytes *)malloc(sizeof(character_bytes));
  ch->byte_data->sprite_facing_right_bytes =
      (unsigned char *)malloc(buffer_size * sizeof(unsigned char));
  ch->byte_data->sprite_facing_left_bytes =
      (unsigned char *)malloc(buffer_size * sizeof(unsigned char));
  ch->byte_data->sprite_facing_right_walking_bytes =
      (unsigned char *)malloc(buffer_size * sizeof(unsigned char));
  ch->byte_data->sprite_facing_left_walking_bytes =
      (unsigned char *)malloc(buffer_size * sizeof(unsigned char));

    //malloc pixel data
  ch->sprite_facing_right_pixels = malloc((player_dims.width * player_dims.height) * sizeof(rgb_value));
  ch->sprite_facing_left_pixels = malloc((player_dims.width * player_dims.height) * sizeof(rgb_value));
  ch->sprite_facing_right_walking_pixels = malloc((player_dims.width * player_dims.height) * sizeof(rgb_value));
  ch->sprite_facing_left_walking_pixels = malloc((player_dims.width * player_dims.height) * sizeof(rgb_value));

  //initialize character memory//
  write_ppm_data(character_sprite_1_ppm, character_sprite_1_txt);
  fill_byte_array(ch->byte_data->sprite_facing_right_bytes, character_sprite_1_ppm, character_sprite_1_txt);
  int rgb_bytes_total = (player_dims.width * player_dims.height) * NUM_POINTS_IN_RGB;
  fill_pixel_array(ch->sprite_facing_right_pixels, ch->byte_data->sprite_facing_right_bytes, rgb_bytes_total);

  //initialize character_facing_left
  write_ppm_data(character_sprite_2_ppm, character_sprite_2_txt);
  fill_byte_array(ch->byte_data->sprite_facing_left_bytes, character_sprite_2_ppm, character_sprite_2_txt);
  rgb_bytes_total = (player_dims.width * player_dims.height) * NUM_POINTS_IN_RGB;
  fill_pixel_array(ch->sprite_facing_left_pixels, ch->byte_data->sprite_facing_left_bytes, rgb_bytes_total);

  //initialize character_animate_right
  write_ppm_data(character_sprite_3_ppm, character_sprite_3_txt);
  fill_byte_array(ch->byte_data->sprite_facing_right_walking_bytes, character_sprite_3_ppm, character_sprite_3_txt);
  rgb_bytes_total = (player_dims.width * player_dims.height) * NUM_POINTS_IN_RGB;
  fill_pixel_array(ch->sprite_facing_right_walking_pixels, ch->byte_data->sprite_facing_right_walking_bytes, rgb_bytes_total);

  //initialze character walk left
  write_ppm_data(character_sprite_4_ppm, character_sprite_4_txt);
  fill_byte_array(ch->byte_data->sprite_facing_left_walking_bytes, character_sprite_4_ppm, character_sprite_4_txt);
  rgb_bytes_total = (player_dims.width * player_dims.height) * NUM_POINTS_IN_RGB;
  fill_pixel_array(ch->sprite_facing_left_walking_pixels, ch->byte_data->sprite_facing_left_walking_bytes, rgb_bytes_total);

  //initialize health pixels
  buffer_size = HEART_WIDTH * HEART_HEIGHT * NUM_RGB_VALUES_IN_PIXEL * NUM_POINTS_IN_RGB;

  write_ppm_data(heart_ppm, heart_txt);
  ch->health_bar_values =
      (unsigned char *)malloc(buffer_size * sizeof(unsigned char));
  fill_byte_array(ch->health_bar_values, heart_ppm, heart_txt);
  rgb_bytes_total = (15 * 13) * NUM_POINTS_IN_RGB;
  ch->health_bar = malloc((15 * 13) * sizeof(rgb_value));
  fill_pixel_array(ch->health_bar, ch->health_bar_values, rgb_bytes_total);

  //initialize character values
  ch->width = player_dims.width;
  ch->height = player_dims.height;
  ch->pos_x = start_x;
  ch->pos_y = start_y;
  ch->direction = RIGHT;
  ch->jumping = FALSE;
  ch->jump_level = 0;
  ch->fake_pos_x = 0;
  ch->moving_right = FALSE;
  ch->moving_left = FALSE;
  ch->health = 2;
  ch->hit_force = 0;
  ch->set_back_npc = 0;
  ch->is_in_enemy_collision = 0;
  
  return ch;
}

enemy* generateEnemy(char* enemy_sprite_1_ppm, char *enemy_sprite_1_txt)
{

  /* get dimention data */

  dimensions enemy_dims = getDimensions(enemy_sprite_1_ppm);
  int buffer_size = enemy_dims.width * enemy_dims.height * NUM_RGB_VALUES_IN_PIXEL * NUM_POINTS_IN_RGB;

  /*allocate memory*/
  enemy *en = (enemy *)malloc(sizeof(enemy));

  en->width = enemy_dims.width;
  en->height = enemy_dims.height;


  en->sprite_facing_right_bytes =
      (unsigned char *)malloc(buffer_size * sizeof(unsigned char));
  en->sprite_facing_right_pixels = malloc((enemy_dims.width * enemy_dims.height) * sizeof(rgb_value));

  //initialize enemy memory
  write_ppm_data(enemy_sprite_1_ppm, enemy_sprite_1_txt);
  fill_byte_array(en->sprite_facing_right_bytes, enemy_sprite_1_ppm, enemy_sprite_1_txt);
  int rgb_bytes_total = (enemy_dims.width * enemy_dims.height) * NUM_POINTS_IN_RGB;
  fill_pixel_array(en->sprite_facing_right_pixels, en->sprite_facing_right_bytes, rgb_bytes_total);

  en->pos_x = 115;
  en->pos_y = 30;
  return en;

}

void free_enemy(enemy* en)
{

  free(en->sprite_facing_right_pixels);
  free(en->sprite_facing_right_bytes);
  free(en);

}


background_image* generateBackground(char* background_pixel_ppm, char* background_pixel_textfile)
{

  background_image *background = (background_image *)malloc(sizeof(background_image));
  return background;

}


void free_character(character* ch)
{

  free(ch->sprite_facing_left_walking_pixels);
  free(ch->sprite_facing_right_walking_pixels);
  free(ch->sprite_facing_left_pixels);
  free(ch->sprite_facing_right_pixels);
  free(ch->health_bar);
  free(ch->health_bar_values);
  free(ch->byte_data->sprite_facing_left_walking_bytes);
  free(ch->byte_data->sprite_facing_right_walking_bytes);
  free(ch->byte_data->sprite_facing_left_bytes);
  free(ch->byte_data->sprite_facing_right_bytes);
  free(ch->byte_data);

  free(ch);
}

void free_background(background_image* background)
{
  free(background);
}

int get_draw_pos_x(character* ch)
{

  int draw_pos_x;
  draw_pos_x = ch->pos_x;

  if( (ch->pos_x > CHARACTER_LOCK_POINT) && (ch->pos_x < (BACKGROUND_WIDTH - CHARACTER_LOCK_POINT)))
  {

    draw_pos_x = CHARACTER_LOCK_POINT;
  } 

    if(ch->pos_x >= (BACKGROUND_WIDTH - CHARACTER_LOCK_POINT))
  {

    draw_pos_x = ch->pos_x - 200;
  } 
  return draw_pos_x;
}

void draw_to_screen(SDL_Renderer *renderer, character* ch) {

  int draw_ch_pos_x = get_draw_pos_x(ch);

  time_t seconds;
  seconds = time(NULL);

  int array_position = 0;
  rgb_value draw_value;
  int transparency = 255;
  for (int i = 0 + ch->pos_y; i < ch->height + ch->pos_y; i++) { 

    for (int j = 0 + draw_ch_pos_x; j < ch->width + draw_ch_pos_x; j++) {

      if(ch->direction == RIGHT)
      {

      if( (int)seconds % 2 == 0 )
        {
         draw_value = ch->sprite_facing_right_walking_pixels[array_position]; 

        }
        else{
        draw_value = ch->sprite_facing_right_pixels[array_position]; 
        }

      }

      if(ch->direction == LEFT)
      {


      if( (int)seconds % 2 == 0 )
        {
         draw_value = ch->sprite_facing_left_pixels[array_position]; 

        }
        else{
        draw_value = ch->sprite_facing_left_walking_pixels[array_position]; 
        }
        
    
      }

      int r = (int)draw_value.r;
      int g = (int)draw_value.g;
      int b = (int)draw_value.b;

      
      SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    
  //     if(!( (draw_value.r == 1) && (draw_value.g == 1) && (draw_value.b == 1)))
	// {
	//   transparency = 255;
	// } else
	// {
	//   transparency = 0;
	// }   


//red, top
  if( (i == ch->pos_y))
  {
      r = 255;
      g = 0;
      b = 0;

  } 

//green
    if( (i == ch->pos_y + ch->height - 1))
  {
      r = 0;
      g = 255;
      b = 0;

  } 
  
  //yellow
  if(j == draw_ch_pos_x )
    {
      r = 255;
      g = 255;
      b = 0;
    }

    //blue

  if(j == draw_ch_pos_x + ch->width - 1)
    {
      r = 0;
      g = 0;
      b = 255;
  }


    SDL_SetRenderDrawColor(renderer, r, g, b, transparency);
	  SDL_RenderDrawPoint(renderer, j, i);
	  array_position += 1;

	  transparency = 255; //reset transparency
    }
  }

  /* SDL_RenderPresent(renderer); */
}

int check_enemy_collision(character* ch, enemy* en, int is_jumping)
{

  int draw_pos_x = get_draw_pos_x(ch);

  int char_x = ch->pos_x + 1;
  int char_y = ch->pos_y + 1;

  int char_max_x = ch->pos_x + ch->width + 1;
  int char_max_y = ch->pos_y + ch->height + 1;


  int enemy_x = en->pos_x + 1;
  int enemy_y = en->pos_y + 1;

  int enemy_max_x = en->pos_x + en->width + 1;
  int enemy_max_y = en->pos_y + en->height + 1;


  if( (char_max_x > enemy_x) && (char_max_y > enemy_y) && (char_x < enemy_max_x) && (char_y < enemy_max_y))
  {
    
      if((ch->pos_y == en->pos_y) && is_jumping)
      { 
        ch->jumping = TRUE;

      }

        printf("\n\n\n\n\n enemy collision  \n\n\n char x and y (%d, %d ) : enemy x and y (%d, %d) ", char_max_x, char_max_y, enemy_x, enemy_y);

        if(ch->hit_force == 0)
        {

        }

        if(ch->direction == RIGHT)
        {
          // ch->pos_x -= 1;
          // ch->fake_pos_x -= 1;
          // ch->pos_y -= 1;

          return 1;

        }

        if(ch->direction == LEFT)
        {

          ch->pos_x += 1;
          ch->fake_pos_x += 1;
          ch->pos_y -= 1;
          return 1;

        }
  
  } else {

      return 0;
  }

  }

void draw_enemy_to_screen(SDL_Renderer *renderer, int** collision_map, enemy* en, character* ch, int frame_left_val) {

  printf("\n\n\n\n\n\n\n\n DRAWING ENEMY %d %d!!!!! \n\n\n\n !!!! \n\n\n\n !!!!n", en->width, en->height);

  int array_position = 0;
  rgb_value draw_value;
  int transparency = 255;

  int offset = 0; 

    for (int i = 0; i < en->height; i++) { 

    for (int j = 0; j < en->width; j++) {

         draw_value = en->sprite_facing_right_pixels[array_position]; 

      int r = (int)draw_value.r;
      int g = (int)draw_value.g;
      int b = (int)draw_value.b;

      
      SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    
      if(!( (draw_value.r == 1) && (draw_value.g == 1) && (draw_value.b == 1)))
	{
	  transparency = 255;
	} else
	{
	  transparency = 0;
	}
 
      int draw_pos_x = en->pos_x - frame_left_val;

    SDL_SetRenderDrawColor(renderer, r, g, b, transparency);
	  SDL_RenderDrawPoint(renderer, draw_pos_x + j, en->pos_y + i);


      array_position += 1;

      }
    }

}

update_enemy_position(enemy* en)
{

  if(en->pos_y == 30)
  {
    en->jumping = TRUE;
    en->jump_level += 1;
  }

  if(en->jumping == TRUE)
  {
    en->pos_y += 1;
  }

  if(en->pos_y == 120)
  {
    en->jumping = FALSE;
  }

if(en->jumping == FALSE)
{
  en->pos_y -= 1;
}



}


draw_character_bounding_box(character* ch)
{
  for(int i = 0; i < PLAYER_HEIGHT; i++)
  {
    for(int j = 0; j < PLAYER_WIDTH; j++)
    {
      

      

    }
  }
}

void draw_health_to_screen(SDL_Renderer *renderer, int** collision_map, character* ch) {

  int array_position = 0;
  rgb_value draw_value;
  int transparency = 255;

  int offset = 0;

    for (int i = 0; i < HEART_HEIGHT; i++) { 

    for (int j = 0; j < HEART_WIDTH; j++) {

         draw_value = ch->health_bar[array_position]; 

               int r = (int)draw_value.r;
      int g = (int)draw_value.g;
      int b = (int)draw_value.b;

      
      SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    
      if(!( (draw_value.r == 1) && (draw_value.g == 1) && (draw_value.b == 1)))
	{
	  transparency = 255;
	} else
	{
	  transparency = 0;
	}

      //printf("\n drawing");
      	  SDL_SetRenderDrawColor(renderer, r, g, b, transparency);

    if(ch->health == 1) {
	  SDL_RenderDrawPoint(renderer, j + 2, i + 2);
    }

    if(ch->health == 2){
    SDL_RenderDrawPoint(renderer, j + 2, i + 2);
    SDL_RenderDrawPoint(renderer, j + 18, i + 2);


    }

              array_position += 1;

      }
    }

}



void draw_collision_to_screen(SDL_Renderer *renderer, int** collision_map, character* ch) {

  int array_position = 0;
  rgb_value draw_value;
  int transparency = 255;

  int offset = 0;

    // if(ch->pos_x > 100)
    // {
    //   offset = ch->pos_x - 100;
    // }

  for (int i = 0; i < 200; i++) { 

    for (int j = 0; j < 400; j++) {

        int map_value = collision_map[i][j];

  if( (map_value == 88) ) 
    {
      //printf("\n\n\ncollision detected");



      int r = 255;
      int g = 0;
      int b = 0;

      

      //printf("\n drawing");
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	  SDL_RenderDrawPoint(renderer, j, i);
    //printf("drawing at %d %d \n", i, j);
	  array_position += 1;

    }
    }
  }

  SDL_RenderPresent(renderer); 
}







int** create2DCollisionMapArray(char* map_file, int width, int height)
{

    //printf("\n\n\n hiiiiiii \n\n");
  int c;
  int** collision_array = (int **)malloc(height * sizeof(int*));

  for (int i = 0; i < height; i++) {
    collision_array[i] = (int *)malloc(width * sizeof(int));
    //printf("\n\n\n hiiiiiii \n\n");
  }

   FILE *sample_data = fopen(map_file, "rb");

   // printf("\n\n\ngot here hiiiiiii \n\n");

   int i = 0;
   int j = 0;
   int count = 0;
   

     while ((c = fgetc(sample_data)) != EOF)
       {
	    //printf("%c\n", c);
      //printf("%d %d\n", i, j);

	 if(c == ' ')
	   {
	     continue;
	   }
	 
	 if(c != '\n')
	   {
	     collision_array[i][j] = c;

       if(c == 88)
       {
          //printf("collision place: %d, %d", i, j);
       }
       else if(c == 79){
                  //printf("\nwhitespace: %d, %d", i, j);
       }
       //printf("\n\n c is : %d count is : %d", c, count);
       count += 1;
	     if((j + 1) != 400)
	       {
	     j = j + 1;
	   }
	 }

	 if(c == '\n')
	   {
	     if((i + 1) != 400)
	       {
		 i = i + 1;
		 j = 0;
	       }
	   }
       }

     //printf("end of function");
     return collision_array;
}

void free2DCollisionMapArray(int** collision_array, int height)
{

  for (int i = 0; i < height; i++) {
        free(collision_array[i]);
    }
    free(collision_array);
  
}

int collision_detected(character* ch, int** collision_map)
{

  int map_value;

  if(ch->direction == RIGHT)
  {
      map_value = collision_map[ch->pos_y + 16][ch->pos_x + 5];
  }
    if(ch->direction == LEFT)
  {
      map_value = collision_map[ch->pos_y + 16][ch->pos_x + 5];
  }
  

  if( (map_value == 88) ) 
    {
      //printf("\n\n\ncollision detected");
        //printf("\n collision character coordinates: x%d y%d", ch->pos_x, ch->pos_y);
      return 1;
    }

  
  //printf("\nmap value is: %i ", map_value);  
  //printf("\ncharacter coordinates: x%d y%d", ch->pos_x, ch->pos_y);
  
  return 0;
}

int character_fell_out_of_bounds(character* ch)
{

  if(ch->pos_y > 180)
  {
    ch->direction = RIGHT;
    return 1;
  }
 
  return 0;
}


int is_front_collision_right(character* ch, int** collision_map)
{

if(ch->direction = RIGHT)
{
  for(int i = 0; i < ch->height; i++)
  {
    if(collision_map[(ch->pos_y) + i][ch->pos_x + 10] == 88)
    {
      return 1;
    }

  }
  return 0;
}
}

int is_front_collision_left(character* ch, int** collision_map)
{

if(ch->direction = LEFT)
{
  for(int i = 0; i < ch->height; i++)
  {
    if(collision_map[(ch->pos_y) + i][ch->pos_x - 2] == 88)
    // add buffer from platform
    {
      return 1;
    }

  }
  return 0;
}
}



void update_player_position(character* ch, int** collision_map, int force)
{

  if(ch->moving_right)
    {

    if(is_front_collision_right(ch, collision_map))
    {
      if(ch->jump_level >= MAX_JUMP)
      {
        ch->direction = RIGHT;
        ch->jumping = FALSE;
        ch->jump_level = 0;
        printf("\n\n\nFRONT COLLISION");
      }
    }
    else 
    {

      ch->pos_x = ch->pos_x + 1;
      ch->fake_pos_x = ch->fake_pos_x + 1;
      ch->direction = RIGHT;

        if( (ch->pos_x > 100) && (ch->pos_x < 300))
  {

          ch->set_back_npc -= 1;
  } 

    }
  

    }

    if(ch->moving_left)
    {

      if(is_front_collision_left(ch, collision_map))
      {
        if(ch->jump_level >= MAX_JUMP){

        ch->direction = LEFT;
        ch->jumping = FALSE;
        ch->jump_level = 0;
        printf("\n\n\nFRONT COLLISION");
        }
      } else
      {

      ch->pos_x = ch->pos_x - 1;
      ch->fake_pos_x = ch->fake_pos_x - 1;
      ch->direction = LEFT;

              if( (ch->pos_x > 100) && (ch->pos_x < 300))
  {

          ch->set_back_npc += 1;
  } 

      }
    }

    if (ch->jumping) {
      printf("jump level: %d\n", ch->jump_level);

      ch->pos_y = ch->pos_y - 1;
      ch->jump_level += 1;

      if (ch->jump_level > MAX_JUMP) {
        ch->jumping = FALSE;
        ch->jump_level = 0;
      }
    }


  

}

void key_press_right(character* ch)
{
  ch->moving_right = TRUE;
  ch->direction = RIGHT;
}

void key_press_left(character* ch)
{
  ch->moving_left = TRUE;
  ch->direction = LEFT;
}

void key_press_space(character* ch)
{

  
}

int is_new_scene_enterance(character* ch, int** collision_map)
{
  if( (collision_map[ch->pos_x][ch->pos_y]) != 88 || (collision_map[ch->pos_x][ch->pos_y] != 76))
  {
    int enterance_val = collision_map[ch->pos_x][ch->pos_y];
    return 1;
  }
  return 0;

}

void key_press_down(character* ch)
{



}


void key_release_right(character* ch)
{
  ch->moving_right = FALSE;
}


void key_release_left(character* ch)
{
  ch->moving_left = FALSE;
}


void key_release_space(character* ch)
{
  printf("\n jumping stopped");
  ch->jumping = FALSE;
  ch->jump_level = 0;
}


camera_coordinates update_viewpoint_coordinates(character* ch)
{
  camera_coordinates scene_view;

  if(ch->pos_x = LOCK_SCREENPOINT)
  {

  }

  


}