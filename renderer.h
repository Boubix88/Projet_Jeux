#ifndef renderer_H
#define renderer_H
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include <SDL2/SDL.h>
#include <SDL_ttf.h>


typedef struct screen_s
{
   SDL_Window *window;
   SDL_Renderer *renderer;
   SDL_Surface* icon;
   SDL_Surface* sky;
   SDL_Texture* skyTexture;
   SDL_Surface* skyDest;

   TTF_Font* font;


}screen_t;
SDL_Renderer *SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags);


void Init_Screen(screen_t*screen);
#endif