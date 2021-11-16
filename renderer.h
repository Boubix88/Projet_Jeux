#ifndef renderer_H
#define renderer_H
#include <stdio.h>
#include <stdlib.h>
#include "map.h"


typedef struct screen_s screen_t;
struct screen_s{
   SDL_Window *window;
   SDL_Renderer *renderer


};




SDL_Renderer *SDL_CreatRenderer(SDL_Window* window, int index, Uint32 flags);




void Init_Screen(screen_t*screen);
#endif