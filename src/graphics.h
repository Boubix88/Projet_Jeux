#ifndef renderer_H
#define renderer_H
#include <stdio.h>
#include <stdlib.h>
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

   SDL_Surface* ground;
   SDL_Texture* groundTexture;

   SDL_Surface* degrade;
   SDL_Texture* degradeTexture;

   SDL_Surface* menu;
   SDL_Texture* menuTexture;

   SDL_Surface* crosshair;
   SDL_Texture* crosshairTexture;

   SDL_Surface* pistolet;
   SDL_Texture* pistoletTexture;

   SDL_Surface* ammo;
   SDL_Texture* ammoTexture;

   SDL_Surface* continuerS;
   SDL_Texture* continuerTexture;
   SDL_Surface* graphismes;
   SDL_Texture* graphismesTexture;
   SDL_Surface* quitter;
   SDL_Texture* quitterTexture;
   SDL_Surface* flou;
   SDL_Texture* flouTexture;

   SDL_Surface* murBrique;
   SDL_Texture* murBriqueTexture;

   SDL_Surface* robot;
   SDL_Texture* robotTexture;

   TTF_Font* font;


}screen_t;

void Init_Screen(screen_t*screen);

#endif