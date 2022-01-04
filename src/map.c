#include "main.h"

void createMap(world_t* world){
  char map[16][16] = {"1111111111111111",
                      "1   1     1   11",
                      "1   1     1   11",
                      "1121111211112111",
                      "6   5    4     1",
                      "11111111111111 1",
                      "1  5         1 6",
                      "6  1     11221 1",
                      "1            1 6",
                      "1    1 1     141",
                      "1      6     1 6",
                      "1      1       1",
                      "1111   4   1   6",
                      "1    1  1 1  1 1",
                      "3    1       1 6",
                      "1111111116116161"}; 
                      
  for (short i = 0; i < 16; i++){
    for (short j = 0; j < 16; j++){
      world->map[i][j] = map[i][j];
    }
  }
}

void draw3DMapSdl(screen_t* screen, world_t *world){
   SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(screen->renderer);
  drawSky(screen);
  drawGround(screen);

	//SDL_SetRenderDrawColor(screen->renderer, 0, 200, 255, SDL_ALPHA_OPAQUE);
  	for (short r=0; r<world->graphismeOptionRayon; r++) { 
  		float angle = world->player_a - FOV/2 + FOV*r/world->graphismeOptionRayon;      
      //Pour regler la fluidité des fps, modifier l'incrementation de t, .001 => 30 fps, .002 => 60 fps, .05 => 144 fps 
        for (float t = 0; t < 16; t += world->graphismeOption) {
          float cx = world->player_x + t * cos(angle);
          float cy = world->player_y + t * sin(angle);
          for (int m = 0; m < world->difficulte; m++) {
            if ((cx <= world->monstre[m].xMap + 0.01 && cx >= world->monstre[m].xMap - 0.01) && (cy <= world->monstre[m].yMap + 0.01 && cy >= world->monstre[m].yMap - 0.01)) {
              drawMonstre3D(world, screen,m, t, r);
            }
          }

          if (world->map[(int)(cy)][(int)(cx)] != ' ' ) {
            int line_height = HEIGHT / t;
            for (short i = 0; i <10; i++) {
              SDL_Rect srcRect;
              SDL_Rect destRect;
              float arrondcx = cx - floor(cx + .5);
              float arrondcy = cy - floor(cy + .5);
              srcRect.x = arrondcx * WALL_SIZE;
              if (fabs(arrondcy) > fabs(arrondcx)) {
                srcRect.x = arrondcy * WALL_SIZE;
              }
              srcRect.h = 256;
              destRect.x = r*world->graphismeOptionWidth * 2.5 + i;
              destRect.y = (HEIGHT / 1.45) - (line_height / 2);
              destRect.h = line_height;
              destRect.w = world->graphismeOptionWidth;

              if (world->map[(int)(cy)][(int)(cx)] == '1') {
                srcRect.w = WALL_SIZE;
                SDL_RenderCopy(screen->renderer, screen->murBriqueTexture, &srcRect, &destRect);
              }else if (world->map[(int)(cy)][(int)(cx)] == '2') {
                srcRect.w = WALL_SIZE/2;
                SDL_RenderCopy(screen->renderer, screen->barreauPorteTexture, &srcRect, &destRect);
              }
              else if (world->map[(int)(cy)][(int)(cx)] == '3') {
                srcRect.w = WALL_SIZE / 2;
                SDL_RenderCopy(screen->renderer, screen->exitDoorTexture, &srcRect, &destRect);
               }
              else if (world->map[(int)(cy)][(int)(cx)] == '4') {
                  srcRect.w = WALL_SIZE / 2;
                  SDL_RenderCopy(screen->renderer, screen->policierGardeTexture, &srcRect, &destRect);
              }
              else if (world->map[(int)(cy)][(int)(cx)] == '5') {
                    srcRect.w = WALL_SIZE/2;
                    SDL_RenderCopy(screen->renderer, screen->tonyLeMechantTexture, &srcRect, &destRect);
              }
              else if (world->map[(int)(cy)][(int)(cx)] == '6') {
                  srcRect.w = WALL_SIZE / 2;
                  SDL_RenderCopy(screen->renderer, screen->murCellulePrison, &srcRect, &destRect);
              }
              }
            break;
          }
        }
    }
  	
  applyCrosshair(screen);  
  drawFPS(world, screen);

  drawMiniMap(screen, world);
  if (world->fpsView == false) {
    applyPistolet(screen);
  }else {
    applyViseeFpsPistolet(screen);
  }

  if (world->ammoShooted) {
    SDL_SetRenderDrawColor(screen->renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
    if (world->ammo.x >= SCREEN_WIDTH / 2 && world->ammo.y >= SCREEN_HEIGHT / 2 && world->fpsView == false) {
          drawAmmo(screen, world);
    }
    world->ammo.x -= 20.4;
    world->ammo.y -= 25.6;
    world->ammo.h -= 0.5;
     world->ammo.w -= 0.5;
     float angle = world->player_a - FOV / 2 + FOV * 256 / 512;
     float cx = world->player_x + world->ammo.direction * cos(angle);
     float cy = world->player_y + world->ammo.direction * sin(angle);

     if (world->map[(int)cy][(int)cx] == '1' || world->map[(int)cy][(int)cx] == '2' || world->map[(int)cy][(int)cx] == '4' || world->map[(int)cy][(int)cx] == '5' || world->map[(int)cy][(int)cx] == '6') {
         world->ammoShooted = false;
         world->ammo.x = SCREEN_WIDTH / 2 + 70;
         world->ammo.y = SCREEN_HEIGHT / 2 + 80;
         world->ammo.w = AMMO_WIDTH;
         world->ammo.h = AMMO_HEIGHT;
     }

      if(world->map[(int)cy][(int)cx] == '2'){
        world->map[(int)cy][(int)cx] = ' ';
        world->score = world->score + 1;
      }

      if (world->map[(int)cy][(int)cx] == '4') {
          world->map[(int)cy][(int)cx] = ' ';
          world->score = world->score + 2;
      }

      if (world->map[(int)cy][(int)cx] == '5') {
          world->score = world->score + 5;
          world->map[(int)cy][(int)cx] = ' ';
          world->tonyMort = true;
      }
      if (world->map[(int)cy][(int)cx] == '3' && world->tonyMort == true) {
          world->objectif = true;
      }
      for (int i = 0; i < world->difficulte; i++){
      if (cx >= world->monstre[i].xMap - 1 && cx <= world->monstre[i].xMap + 1 && cy >= world->monstre[i].yMap - 1 && cy <= world->monstre[i].yMap + 1){
        world->monstre[i].xMap = 20;
        world->monstre[i].yMap = 20;
        world->score = world->score +3;
      }
    }
      
    world->ammo.xMap += cx/32;
    world->ammo.yMap += cy/32;
    world->ammo.direction += 0.5;
    SDL_RenderDrawLine(screen->renderer, 8 + world->player_x*8 , 586 + world->player_y*8, 8 + cx*8, 586 + cy*8);

  }
  drawExplosion(screen, world);
  if (world->compteurNbreImpact == 4) {
      world->compteurNbreImpact = 0;
  }
	SDL_RenderPresent(screen->renderer);
}

void drawSky(screen_t* screen){


  SDL_Rect srcRect;
  SDL_Rect destRect;
  
  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = SCREEN_WIDTH;
  srcRect.h = SCREEN_HEIGHT/2;

  destRect.x = 0;
  destRect.y = 0;
  destRect.w = SCREEN_WIDTH;
  destRect.h = SCREEN_HEIGHT/2;

  SDL_RenderCopy(screen->renderer, screen->skyTexture, &srcRect, &destRect);

}

void drawGround(screen_t* screen){
  SDL_Rect srcRect;
  SDL_Rect destRect;
  SDL_Rect degradeDestRect;

  srcRect.x = 0;
  srcRect.y = 0; 
  srcRect.w = FLOOR_SIZE;
  srcRect.h = FLOOR_SIZE;

  destRect.x = 0;
  destRect.y = SCREEN_HEIGHT/2; 
  destRect.w = SCREEN_WIDTH;  
  destRect.h = SCREEN_HEIGHT-250;  

  degradeDestRect.x = 0;
  degradeDestRect.y = SCREEN_HEIGHT/2;
  degradeDestRect.w = SCREEN_WIDTH;
  degradeDestRect.h = 64;

  SDL_RenderCopy(screen->renderer, screen->groundTexture, &srcRect, &destRect);
  SDL_RenderCopy(screen->renderer, screen->degradeTexture, &srcRect, &degradeDestRect);
}

void drawMonstre3D(world_t* world, screen_t* screen,int k,float t, short r) {
        float sprite_dir = atan2(world->monstre[k].yMap - world->player_y, world->monstre[k].xMap - world->player_x);
        while (sprite_dir - world->player_a > M_PI) {
            sprite_dir -= 2 * M_PI;
        }

        while (sprite_dir - world->player_a < -M_PI) sprite_dir += 2 * M_PI;

        float sprite_dist = t;
        int  sprite_screen_size = fmin(1000,(HEIGHT / sprite_dist));
        int h_offset = (sprite_dir - world->player_a) * (HEIGHT/2) / (FOV) + (HEIGHT/2)/2 - sprite_screen_size / 2;
        int v_offset = HEIGHT/2 - sprite_screen_size/2 ;
        if (h_offset  > HEIGHT || h_offset <= WIDTH + 300) {
          if (v_offset < HEIGHT || v_offset >= 0) {
            SDL_Rect destRect;
            destRect.x = h_offset + r*2 - 100 - sprite_screen_size;
            destRect.y = v_offset + r/16 + sprite_screen_size/2;
            destRect.h = (h_offset+sprite_screen_size*4)/sprite_dist/2;
            destRect.w = (v_offset + sprite_screen_size*4)/sprite_dist/2;

            world->monstre[k].x = h_offset + r*2 - sprite_screen_size;
            world->monstre[k].y = v_offset + r/16 + sprite_screen_size/2;
            SDL_RenderCopy(screen->renderer, screen->robotTexture, NULL, &destRect);
            }
        }
}