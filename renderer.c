#include <stdio.h>
#include <stdlib.h>

typedef struct screen_s screen_t;
struct screen_s{
   SDL_Window *window;


};



void Init_Screen(screen_t*screen){
    screen->window=SDL_CreateWindow("Prison Survival",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1280,720,SDL_WINDOW_RESIZABLE);


}


SDL_Renderer * SDL_CreateRenderer(SDL_Window * window,
                       int index, Uint32 flags);



SDL_SetRenderDrawColor