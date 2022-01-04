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

   SDL_Texture* menuStartTexture;
   SDL_Texture* plusTexture;
   SDL_Texture* moinsTexture;
   SDL_Texture* startTexture;
   
   SDL_Surface* sky;
   SDL_Texture* skyTexture;
   SDL_Surface* skyDest;

   SDL_Surface* ground;
   SDL_Texture* groundTexture;

   SDL_Surface* degrade;
   SDL_Texture* degradeTexture;

   SDL_Surface* menu;
   SDL_Texture* menuTexture;

   SDL_Texture* crosshairTexture;

   SDL_Texture* pistoletTexture;

   SDL_Texture* ammoTexture;

   SDL_Surface* continuerS;
   SDL_Texture* continuerTexture;
   SDL_Surface* graphismes;
   SDL_Texture* graphismesTexture;
   SDL_Surface* quitter;
   SDL_Texture* quitterTexture;
   SDL_Surface* flou;
   SDL_Texture* flouTexture;

   SDL_Texture* menuGraphisme;
   SDL_Texture* tresHautGraphisme;
   SDL_Texture* hautGraphisme;
   SDL_Texture* normalGraphisme;
   SDL_Texture* basGraphisme;
   SDL_Texture* tresBasGraphisme;


   SDL_Texture* murBriqueTexture;

   SDL_Texture* exitDoorTexture;
   SDL_Texture*	barreauPorteTexture;
   SDL_Texture*	policierGardeTexture;
   SDL_Texture*	tonyLeMechantTexture;

   SDL_Texture* murCellulePrison;

   SDL_Texture* robotTexture;

   TTF_Font* font;

   SDL_Surface *textSurface;
   SDL_Texture *text;

   SDL_Surface *fpsSurface;
   SDL_Texture *fpsTexture;

   SDL_Texture* impactAmmoTexture;

}screen_t;

void Init_Screen(screen_t*screen);

#endif