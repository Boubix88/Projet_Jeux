#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "renderer.h"




void Init_Screen(screen_t*screen){
    screen->window = SDL_CreateWindow("Prison Survival",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1280,720,SDL_WINDOW_RESIZABLE);
    //screen->renderer = SDL_CreateRenderer(screen->window,-1,0);
    /*SDL_RenderClear(screen->renderer);
    SDL_RenderPresent(screen->renderer);*/
}

int main(int argc, char *argv[]){
    screen_t* screen;
    SDL_Init(SDL_INIT_VIDEO);
    Init_Screen(screen);
    SDL_Quit();
    return EXIT_SUCCESS;
}