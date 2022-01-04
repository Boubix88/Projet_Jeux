#include "main.h"

//Taille map : 128x128 px   16*8
void drawMiniMap(screen_t* screen, world_t* world) {
  drawWalls(screen, world);
  drawPlayer(screen, world);
  drawFov(screen, world);
  drawMonstre(screen, world);
}

void drawWalls(screen_t *screen, world_t* world){
  SDL_Rect destRect;
  destRect.x = 8;
  destRect.y = 586;
  destRect.w = 128;
  destRect.h = 128;

  SDL_SetRenderDrawColor(screen->renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(screen->renderer, &destRect);

  destRect.x = 0;
  destRect.y = 586;
  destRect.w = 8;
  destRect.h = 8;
  
  SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, 255);
  for (short i=0; i<16; i++){
    destRect.x += 8;
    for (short j=0; j<16; j++){
      if (world->map[j][i] != ' ') {
        destRect.y = 586 + j*8;
        SDL_RenderFillRect(screen->renderer, &destRect);
      }
    }  
  }  
}

void drawPlayer(screen_t* screen, world_t* world){
  SDL_Rect destRect;
  destRect.w = 3;
  destRect.h = 3;
  destRect.y = 586 + world->player_y*8;
  destRect.x = 8 + world->player_x*8;

  SDL_SetRenderDrawColor(screen->renderer, 124, 0, 200, 255);
  SDL_RenderFillRect(screen->renderer, &destRect);

}

void drawFov(screen_t* screen, world_t* world){
  for (short r=0; r<512; r++) { 
    float angle = world->player_a - FOV/2 + FOV*r/512;      
    SDL_SetRenderDrawColor(screen->renderer, 0, 0, 255, 255);
    for (float t=0; t<20; t+=.05) {
        float cx = world->player_x + t*cos(angle);
        float cy = world->player_y + t*sin(angle);

        if (world->map[(int)(cy)][(int)(cx)] != ' '){
          break;
        } 
        int pixx = 8 + cx*8;
        int pixy = 586 + cy*8;
        SDL_RenderDrawPoint(screen->renderer, pixx, pixy);
    }
  }  
}

void drawMonstre(screen_t* screen, world_t* world) {
  SDL_SetRenderDrawColor(screen->renderer, 255, 0, 0, 122);
  for (short i = 0; i < DIFFICULTE; i++) {
      SDL_Rect destRect;
      destRect.w = 3;
      destRect.h = 3;
      destRect.y = 586 + world->monstre[i].yMap * 8;
      destRect.x = 8 + world->monstre[i].xMap * 8;

      SDL_RenderFillRect(screen->renderer, &destRect);
  }
}