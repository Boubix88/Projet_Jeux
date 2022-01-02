#include "main.h"

void createMap(world_t* world){
  char map[16][16] = {"1111111111111111",
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
                      
  for (int i = 0; i < 16; i++){
    for (int j = 0; j < 16; j++){
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
  	for (int r=0; r<512; r++) { 
  		float angle = world->player_a - FOV/2 + FOV*r/512;      
      //Pour regler la fluidité des fps, modifier l'incrementation de t, .001 => 30 fps, .002 => 60 fps, .05 => 144 fps 
  		for (float t=0; t<20; t+=.002) {
      		float cx = world->player_x + t*cos(angle);
      		float cy = world->player_y + t*sin(angle);

        	if (world->map[(int)(cy)][(int)(cx)]=='1'){
        		int line_height = HEIGHT/t;
		  		  for (int i = 0; i < 16; i++){
              SDL_Rect srcRect;
              SDL_Rect destRect;
              float arrondcx = cx - floor(cx + .5);
              float arrondcy = cy - floor(cy + .5);
              srcRect.x = arrondcx*WALL_SIZE;
              if (fabs(arrondcy) > fabs(arrondcx)) {
                  srcRect.x = arrondcy * WALL_SIZE;
              }
              srcRect.h = WALL_SIZE;
              srcRect.w = WALL_SIZE;
              destRect.x = r*2.5+i;
              destRect.y = (HEIGHT/2) - (line_height/2);
              destRect.h = line_height;
              destRect.w = 1;
              SDL_RenderCopy(screen->renderer, screen->murBriqueTexture, &srcRect, &destRect);
		  		  }
        		break;
      		}
            /**for (int m = 0; m < DIFFICULTE; m++) {
                if (world->map[(int)(cy)][(int)(cx)] == world->map[(int)world->monstre[m].y][(int)world->monstre[m].x]) {
                    drawMonstre3D(world,screen,m);
                }
            }**/

            /**if (world->map[(int)(cy)][(int)(cx)] == '2') {
                int line_height = HEIGHT / t;
                for (int i = 0; i < 16; i++) {
                    //SDL_RenderDrawLine(screen->renderer, r*2.5+i , (HEIGHT+line_height)/2, r*2.5+i, (HEIGHT-line_height)/2);
                    SDL_Rect srcRect;
                    SDL_Rect destRect;
                    float arrondcx = cx - floor(cx + .5);
                    float arrondcy = cy - floor(cy + .5);
                    srcRect.x = arrondcx * WALL_SIZE;
                    if (fabs(arrondcy) > fabs(arrondcx)) {
                        srcRect.x = arrondcy * WALL_SIZE;
                    }
                    srcRect.h = WALL_SIZE;
                    srcRect.w = WALL_SIZE;
                    destRect.x = r * 2 + i/4;
                    destRect.y = (HEIGHT / 2) - (line_height / 2)/4;
                    destRect.h = line_height/2;
                    destRect.w =1 ;
                    SDL_SetRenderDrawColor(screen->renderer,0, 255, 255, 255);
                    SDL_RenderDrawRect(screen->renderer, &destRect);
                }
                break;
            }**/
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
      world->ammo.x = 1280/2 + 70;
      world->ammo.y = 720/2 + 80;
      world->ammo.w = AMMO_WIDTH;
      world->ammo.h = AMMO_HEIGHT;
    }
      
    world->ammo.xMap += cx/32;
    world->ammo.yMap += cy/32;
    world->ammo.direction += 0.5;
    SDL_RenderDrawLine(screen->renderer, 8 + world->player_x*8 , 586 + world->player_y*8, 8 + cx*8, 586 + cy*8);
  }
  
	SDL_RenderPresent(screen->renderer);
}

void drawSky(screen_t* screen, world_t* world){
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = world->player_a*800;
  srcRect.y = 0;
  srcRect.w = 1280;
  srcRect.h = 720/2;

  destRect.x = 0;
  destRect.y = 0;
  destRect.w = 1280;
  destRect.h = 720/2-80;

  SDL_RenderCopy(screen->renderer, screen->skyTexture, &srcRect, &destRect);
}

void drawGround(screen_t* screen){
  SDL_Rect srcRect;
  SDL_Rect destRect;
  SDL_Rect degradeDestRect;

  srcRect.x = 0;
  srcRect.y = 0; //0
  srcRect.w = FLOOR_SIZE;
  srcRect.h = FLOOR_SIZE;

  destRect.x = 0;  //0
  destRect.y = 720/2-80; //720/2-80
  destRect.w = 1280;  //1280
  destRect.h = 720-250;  //720-250

  degradeDestRect.x = 0;
  degradeDestRect.y = 720/2-80;
  degradeDestRect.w = 1280;
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
  int  sprite_screen_size = fmin(2000,(HEIGHT / sprite_dist));
  // do not forget the 3D view takes only a half of the framebuffer, thus fb.w/2 for the screen width
  int h_offset = (sprite_dir - world->player_a) * (WIDTH) / (FOV) + (WIDTH) - sprite_screen_size / 2;
  int v_offset = HEIGHT / 2 - sprite_screen_size / 2;

  for (int  i = 0; i < sprite_screen_size; i++) {
    if (h_offset + i < 0 || h_offset + i >= WIDTH) continue;
    for (int j = 0; j < sprite_screen_size; j++) {
      if (v_offset + j < 0 || v_offset + j >= HEIGHT) continue;
      SDL_RenderDrawLine(screen->renderer, h_offset + i, v_offset + j,sprite_screen_size, sprite_screen_size);
    }
  }
}