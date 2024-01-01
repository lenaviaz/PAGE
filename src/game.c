#include <game.h>

int game()
{

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED, 600, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetLogicalSize(renderer, 16, 16);

    int keep_window_open = TRUE;
    while(keep_window_open)
    {

        SDL_Event e;

        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {

            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);

            case SDL_QUIT:
            keep_window_open = 0;

            default:
                break;

            }
        }
    }

    return 0;
}