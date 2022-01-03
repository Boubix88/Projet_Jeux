#include "main.h"

void createMap(world_t* world){
  char map[16][16] = {"1111111111111111",
                      "1   11   11   11",
                      "1   11   11   11",
                      "11 1111 1111 111",
                      "1              1",
                      "11111111111111 2",
                      "1  1         1 1",
                      "1  1   1 11  1 2",
                      "1    1       1 1",
                      "111  1 1  1  1 2",
                      "1      1 1   1 1",
                      "1  1 1 1       2",
                      "1  1       1   1",
                      "1    1  1 1  1 2",
                      "1     1      1 1",
                      "1111111111111121"}; 
                      
  for (short i = 0; i < 16; i++){
    for (short j = 0; j < 16; j++){
      world->map[i][j] = map[i][j];
    }
  }
}

void draw3DMapSdl(screen_t* screen, world_t *world){
	SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(screen->renderer);
  drawSky(screen, world);
  drawGround(screen);

	//SDL_SetRenderDrawColor(screen->renderer, 0, 200, 255, SDL_ALPHA_OPAQUE);
  	for (short r=0; r<world->graphismeOptionRayon; r++) { 
  		float angle = world->player_a - FOV/2 + FOV*r/world->graphismeOptionRayon;      
      //Pour regler la fluidité des fps, modifier l'incrementation de t, .001 => 30 fps, .002 => 60 fps, .05 => 144 fps 
        for (float t = 0; t < 20; t += world->graphismeOption) {
          float cx = world->player_x + t * cos(angle);
          float cy = world->player_y + t * sin(angle);

          if (world->map[(int)(cy)][(int)(cx)] != ' ') {
            int line_height = HEIGHT / t;
            for (short i = 0; i < 16; i++) {
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

  if (world->ammoShooted){
    drawAmmo(screen, world);
    world->ammo.x -= 5.6; //Defaut : 0.7
    world->ammo.y -= 6.4; //Defaut : 0.8
    world->ammo.h -= 0.5;
    world->ammo.w -= 0.5;

    float cx = world->ammo.xMap + world->ammo.direction*cos(world->player_a);
    float cy = world->ammo.yMap + world->ammo.direction*sin(world->player_a);

    if (world->map[(int)cy][(int)cx]=='1'){
      world->ammoShooted = false;
      world->ammo.x = SCREEN_WIDTH/2 + 70;
      world->ammo.y = SCREEN_HEIGHT/2 + 80;
      world->ammo.w = AMMO_WIDTH;
      world->ammo.h = AMMO_HEIGHT;
    }
      
    world->ammo.xMap += cx/32;
    world->ammo.yMap += cy/32;
    world->ammo.direction += 0.5;
    SDL_RenderDrawLine(screen->renderer, 8 + world->player_x*8 , 586 + world->player_y*8, 8 + cx*8, 586 + cy*8);
  }
  /*for (short m = 0; m < DIFFICULTE; m++){
    drawMonstre3D(world, screen, m);
  }*/
	SDL_RenderPresent(screen->renderer);
}

void drawSky(screen_t* screen, world_t* world){
  if (world->angleSky > .5){
    world->angleSky -= .5;
  }else if (world->angleSky < -0.5){
    world->angleSky += .5;
  }

  SDL_Rect srcRect;
  SDL_Rect destRect;
  
  srcRect.x = world->angleSky*800;
  srcRect.y = 0;
  srcRect.w = SCREEN_WIDTH;
  srcRect.h = SCREEN_HEIGHT/2;

  destRect.x = world->angleSky*800;
  destRect.y = 0;
  destRect.w = SCREEN_WIDTH;
  destRect.h = SCREEN_HEIGHT/2;

  SDL_RenderCopy(screen->renderer, screen->skyTexture, &srcRect, &destRect);

  /*if (world->player_a*800 > 1280){
  SDL_Rect srcRect1;
  SDL_Rect destRect1;
  
  srcRect1.x = world->player_a*800 - 1280;
  srcRect1.y = 0;
  srcRect1.w = SCREEN_WIDTH-world->player_a*800;
  srcRect1.h = SCREEN_HEIGHT/2;

  destRect1.x = world->player_a*800 - 1280;
  destRect1.y = 0;
  destRect1.w = SCREEN_WIDTH-world->player_a*800;
  destRect1.h = SCREEN_HEIGHT/2;
  SDL_RenderCopy(screen->renderer, screen->skyTexture, &srcRect1, &destRect1);
  }*/
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

void drawMonstre3D(world_t* world, screen_t* screen,int k) {
        
        float sprite_dir = atan2(world->monstre[k].y - world->player_y, world->monstre[k].x - world->player_x);
        while (sprite_dir - world->player_a > M_PI) {
            sprite_dir -= 2 * M_PI;
        }

        while (sprite_dir - world->player_a < -M_PI) sprite_dir += 2 * M_PI;

        // distance from the player to the sprite
        float sprite_dist = sqrt(pow(world->player_x - world->monstre[k].x, 2) + pow(world->player_y - world->monstre[k].y, 2));
        int  sprite_screen_size = fmin(1000,(HEIGHT / sprite_dist));
        // do not forget the 3D view takes only a half of the framebuffer, thus fb.w/2 for the screen width
        //int h_offset = (sprite_dir - world->player_a) * (WIDTH) / (FOV) + (WIDTH) - sprite_screen_size / 2;
        int h_offset = (sprite_dir - world->player_a) / FOV * (WIDTH/2) - 471 / 2;
        int v_offset = HEIGHT / 2 - sprite_screen_size / 2;
        for (short  i = 0; i < sprite_screen_size; i++) {
            if (h_offset + i < 0 || h_offset + i >= 512/2) continue;
            for (short j = 0; j < sprite_screen_size; j++) {
                if (v_offset + j < 0 || v_offset + j >= HEIGHT) continue;
                //SDL_RenderDrawLine(screen->renderer, i + h_offset, j + v_offset, h_offset+sprite_screen_size, v_offset + sprite_screen_size);
                SDL_Rect destRect;
                destRect.x = i + h_offset;
                destRect.y = j + v_offset;
                destRect.h = h_offset+sprite_screen_size;
                destRect.w = v_offset + sprite_screen_size;
                SDL_RenderCopy(screen->renderer, screen->robotTexture, NULL, &destRect);
            }

        }
}