#include "menu.h"

menu* get_main_menu()
{

    menu* main_menu = (menu *)malloc(sizeof(menu));

  main_menu->menu_window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  main_menu->menu_renderer = SDL_CreateRenderer(main_menu->menu_window, -1, 0); // TODO: is -1 or 0?
  SDL_RenderSetLogicalSize(main_menu->menu_renderer, RENDER_SCALE, RENDER_SCALE);

  return main_menu;
  }


