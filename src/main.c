#include "../include/game_objects.h"
#include <stdio.h>
#include <SDL_image.h>

/* #define TRUE 1 */
/* #define FALSE 0 */

int main(int argc, char *argv[]) {



  int enemy_jumpback = 0;
  int keep_window_open = FALSE;
  const int FPS = 30;
  const int frameDelay = 1000 / FPS; // Maximum time for a frame in milliseconds

  dimensions dim = getDimensions("assets/test.ppm");

  // ----------- load game assets ------------ //

  character* player = generateCharacter("assets/characters/player_sprite_1.ppm",
					"assets/pixel-data-text-files/player_sprite_1.txt",
          "assets/characters/player_sprite_2.ppm",
            "assets/pixel-data-text-files/player_sprite_2.txt",
            "assets/characters/player_sprite_3.ppm",
            "assets/pixel-data-text-files/player_sprite_3.txt",
            "assets/characters/player_sprite_4.ppm",
            "assets/pixel-data-text-files/player_sprite_4.txt",
					25, 
          25,
          "assets/characters/heart.ppm",
          "assets/pixel-data-text-files/heart.txt.txt");

  enemy* fire_enemy = generateEnemy("assets/characters/firecat-small-1.ppm", "assets/pixel-data-text-files/enemy_1.txt");

  background_image* background = generateBackground("../assets/test_assets/pixel-frame-0.ppm",
						    "../assets/pixel-data-text-files/image_1.txt");

    int **cloud_collision_map = create2DCollisionMapArray("assets/collision-maps/collision_map1.txt", 400, 200);

  // -----------------------------------------//
  /*

 */

  // ------------ menu loop -----------------//

  SDL_Init(SDL_INIT_EVERYTHING);
  int keep_menu_open = TRUE;
  menu *main_menu = get_main_menu();

  SDL_Window *window;
  SDL_Renderer *renderer;

  while (keep_menu_open) {
    

    SDL_Event e;
    while (SDL_PollEvent(&e)) {

      switch (e.type) {

      case SDL_QUIT:
        /*

         */

        //---- initialize SDL window -----//
        window = SDL_CreateWindow("Pix", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                  WINDOW_HEIGHT, 0);
        renderer = SDL_CreateRenderer(window, -1, 0); // TODO: is -1 or 0?
        SDL_RenderSetLogicalSize(renderer, RENDER_SCALE, RENDER_SCALE);
        // ------------------------------//

        //sleep(1);
        keep_menu_open = FALSE;
        SDL_DestroyWindow(main_menu->menu_window);
        free(main_menu);
        break;
        /*

         */
      case SDL_KEYDOWN:
	
	if(e.key.keysym.sym == SDLK_RETURN)
	  {
	window = SDL_CreateWindow("Pix", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                  WINDOW_HEIGHT, 0);
        renderer = SDL_CreateRenderer(window, -1, 0); // TODO: is -1 or 0?
        SDL_RenderSetLogicalSize(renderer, RENDER_SCALE, RENDER_SCALE);
        // ------------------------------//

        //sleep(1);
        keep_menu_open = FALSE;
        SDL_DestroyWindow(main_menu->menu_window);
        free(main_menu);

	  }
	
	
        break;
        /*

 */

      default:
        break;
      }
    }
  }

  // --------------------------------------//
  /*











   */
  // -------------- Game Loop -------------//
  Uint32 frameStart, frameTime;
  keep_window_open = TRUE; 

  camera_coordinates camera_view;

  camera_view.x = 0;
  camera_view.y = 0;
  camera_view.width = 200;
  camera_view.height = 200;

  SDL_Texture* background_texture = IMG_LoadTexture(renderer, "assets/backgrounds/scene_1_frame.png"); 
  //int test = background_texture->w; 
  SDL_Rect texture_rect;
texture_rect.x = 0;  //the x coordinate
texture_rect.y = 0; // the y coordinate
texture_rect.w = 200; //the width of the texture
texture_rect.h = 200; //the height of the texture

SDL_Renderer *renderer_test;
renderer_test = SDL_CreateRenderer(window, -1, 0); // TODO: is -1 or 0?
SDL_RenderSetLogicalSize(renderer_test, 600, 600);

  SDL_Texture* dialogue_1 = IMG_LoadTexture(renderer, "assets/backgrounds/Untitled.png"); 

    SDL_Rect texture_rect_1;
texture_rect_1.x = 100;  //the x coordinate
texture_rect_1.y = 50; // the y coordinate
texture_rect_1.w = 200; //the width of the texture
texture_rect_1.h = 200; //the height of the texture

  while (keep_window_open) {


    frameStart = SDL_GetTicks();
    
    if(player->pos_x > 100)
    {
      texture_rect.x = player->pos_x - 100;
      //player->pos_x = player->pos_x - 1;
    }

    if(player->pos_x > 300 )
    {
      texture_rect.x = 200;
    }


    if(character_fell_out_of_bounds(player))
    {

      player->health -= 1;

    if(player->health == 0)
    {
      break;
    }
      player->pos_x = 25;
      player->pos_y = 25;
      player->fake_pos_x = 0;

    
    texture_rect.x = 0;  //the x coordinate
texture_rect.y = 0; // the y coordinate
texture_rect.w = 200; //the width of the texture
texture_rect.h = 200; //the height of the texture

    if(player->pos_x > 100)
    {
      texture_rect.x = player->pos_x - 100;
      //player->pos_x = player->pos_x - 1;
    }

    if(player->pos_x > 300 )
    {
      texture_rect.x = 200;
    }


    }

  printf("\n\n\n char posx: %d", player->pos_x);

    if ((!collision_detected(player, cloud_collision_map)) && (player->jumping == FALSE)) {
      player->pos_y = player->pos_y + 1;
      printf("\n no collision");
    }
    
  check_enemy_collision(player, fire_enemy, 0);

            if(player->pos_x > 100)
    {
      texture_rect.x = player->pos_x - 100;
      //player->pos_x = player->pos_x - 1;

    }

    if(player->pos_x > 300 )
    {
      texture_rect.x = 200;
    }

        
    update_player_position(player, cloud_collision_map, player->hit_force);

    SDL_RenderClear(renderer);
    //draw_to_screen(renderer, player);
    SDL_RenderCopy(renderer, background_texture, &texture_rect, NULL); //memopry leak
    draw_to_screen(renderer, player);
    update_enemy_position(fire_enemy);
        draw_health_to_screen(renderer, cloud_collision_map, player);
    draw_enemy_to_screen(renderer, cloud_collision_map, fire_enemy, player, texture_rect.x);
    //draw_collision_to_screen(renderer, cloud_collision_map, player);
    SDL_RenderPresent(renderer);
    printf("\n\n %d", player->pos_y);

    SDL_Event e;
    while (SDL_PollEvent(&e)) {

      switch (e.type) {
      case SDL_QUIT:
        keep_window_open = FALSE;
        break;

	/*


 
	 */
      case SDL_KEYDOWN:

	if(e.key.keysym.sym == SDLK_RIGHT)

	  {

      if(!check_enemy_collision(player, fire_enemy, 0)) {
	    key_press_right(player);
      }

	  }
	/*

	 */


	 if(e.key.keysym.sym == SDLK_LEFT)

	  {
	    key_press_left(player);

	  }

	 if(e.key.keysym.sym == SDLK_SPACE)

	  {
	    key_press_space(player);

        check_enemy_collision(player, fire_enemy, 1);


        if (collision_detected(player, cloud_collision_map)) {

            player->jumping = TRUE;
          }

	  }

    	 if(e.key.keysym.sym == SDLK_DOWN)

	  {

          SDL_Rect texture_rect_2;
texture_rect_2.x = 0;  //the x coordinate
texture_rect_2.y = 100; // the y coordinate
texture_rect_2.w = 200; //the width of the texture
texture_rect_2.h = 80; //the height of the texture
      //SDL_RenderClear(renderer);

          SDL_RenderClear(renderer);
    //draw_to_screen(renderer, player);
    SDL_RenderCopy(renderer, background_texture, &texture_rect, NULL); //memopry leak
    draw_to_screen(renderer, player);
    draw_health_to_screen(renderer, cloud_collision_map, player);
          SDL_RenderCopy(renderer, dialogue_1, NULL, &texture_rect_2); //memopry leak
    SDL_RenderPresent(renderer);
              SDL_RenderClear(renderer);
    sleep(2);
    
      printf("\n\n key press down");
	    //key_press_left(player);

	  }


	/*

	 */
	break;
      case SDL_KEYUP:

	 if (e.key.keysym.sym == SDLK_RIGHT)
	   {
	     key_release_right(player);
	 }
	/*

	 */
	 if (e.key.keysym.sym == SDLK_LEFT)
	   {
	     key_release_left(player);
	 }
   /*

    */
	 if (e.key.keysym.sym == SDLK_SPACE)
	   {
	     key_release_space(player);
	 }

	 
	 

      default:

	break;
      }
    }
    // Frame management
    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
    
  }

  // -------------------------------------//
  /*













 */
  //clean up
  free2DCollisionMapArray(cloud_collision_map, 200);
  SDL_DestroyTexture(background_texture);
  SDL_DestroyWindow(window);
  free_character(player);
  free_enemy(fire_enemy);
  free(background);

  // free(main_menu); //double free error when I try and free this

  return 0;
}
