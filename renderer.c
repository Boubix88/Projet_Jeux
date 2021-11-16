#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL>

typedef struct screen_s screen_t;
struct screen_s{
   SDL_Window *window;
   SDL_Renderer* *renderer


};



void Init_Screen(screen_t*screen){
    screen->window=SDL_CreateWindow("Prison Survival",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1280,720,SDL_WINDOW_RESIZABLE);
    screen->renderer=SDL_CreateRenderer(screen->window,-1,0);
    


}




SDL_SetRenderDrawColor