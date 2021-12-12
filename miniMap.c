#include "main.h"

void drawMiniMap(screen_t* screen, world_t* world) {
  const char map[16][16] = {"1111111111111111",
                            "1   11   11   11",
                            "1   11   11   11",
                            "11 1111 1111 111",
                            "1              1",
                            "11111111111111 1",
                            "1  1         1 1",
                            "1  1   1 11  1 1",
                            "1    1       1 1",
                            "111  1 1  1  1 1",
                            "1      1 1   1 1",
                            "1  1 1 1       1",
                            "1  1       1   1",
                            "1    1  1 1  1 1",
                            "1     1      1 1",
                            "1111111111111111"}; 
  drawWalls(map, screen);
  drawPlayer(screen, world);
  drawFov(map, screen, world);
}
//128x128 px   16*8
void drawWalls(const char map[16][16], screen_t *screen){
  SDL_Rect destRect;
  destRect.x = 8;
  destRect.y = 586;
  destRect.w = 128;
  destRect.h = 128;

  SDL_SetRenderDrawColor(screen->renderer, 255, 255, 0, 255);
  SDL_RenderFillRect(screen->renderer, &destRect);

  destRect.x = 0;
  destRect.y = 576;
  destRect.w = 8;
  destRect.h = 8;

  for (int i=0; i<16; i++){
    destRect.x += 8;
    for (int j=0; j<16; j++){
      if (map[i][j]=='1') {
        destRect.y = 706 - j*8;
        SDL_SetRenderDrawColor(screen->renderer, 255, 0, 200, 255);
        SDL_RenderFillRect(screen->renderer, &destRect);
      }
    }  
  }    
}

void drawPlayer(screen_t* screen, world_t* world){
  SDL_Rect destRect;
  destRect.w = 3;
  destRect.h = 3;
  destRect.y = 712 - world->player_x*8;
  destRect.x = 8 + world->player_y*8;

  SDL_SetRenderDrawColor(screen->renderer, 0, 255, 0, 255);
  SDL_RenderFillRect(screen->renderer, &destRect);

}

void drawFov(const char map[16][16], screen_t* screen, world_t* world){
  float player_fov = 1.58; 
  
  for (int r=0; r<512; r++) { 
    float angle = world->player_a - player_fov/2 + player_fov*r/512;      
  
    for (float t=0; t<20; t+=.05) {
        float cx = world->player_x + t*cos(angle);
        float cy = world->player_y + t*sin(angle);

        if (map[(int)(cy)][(int)(cx)] != ' '){
          break;
        } 
    
        int pixx = 8 + cx*8;
        int pixy = 576 + cy*8;

        SDL_SetRenderDrawColor(screen->renderer, 0, 255, 100, 255);
        SDL_RenderDrawLine(screen->renderer, 8 + world->player_y*8, 712 - world->player_x*8, pixx, pixy);
    }
  }  
}