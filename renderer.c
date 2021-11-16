#include <SDL2/SDL.h>
#include "renderer.h"


void Init_Screen(screen_t*screen){
    screen->window = SDL_CreateWindow("Prison Survival",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1280,720,SDL_WINDOW_RESIZABLE);
    //screen->renderer = SDL_CreateRenderer(screen->window,-1,0);
    /*SDL_RenderClear(screen->renderer);
    SDL_RenderPresent(screen->renderer);*/
}