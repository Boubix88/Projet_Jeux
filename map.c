#include "renderer.h"
#include "main.h"

void map(screen_t* screen, world_t *world) {
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
  draw3DMapSdl(map, screen, world);
}

void draw3DMapSdl(const char map[16][16], screen_t* screen, world_t *world){
  float player_fov = 1.58;

	SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

  SDL_RenderClear(screen->renderer);

  drawSky(screen, world);
  drawGround(screen, world);

	SDL_SetRenderDrawColor(screen->renderer, 0, 200, 255, SDL_ALPHA_OPAQUE);
  	for (int r=0; r<512; r++) { 
  		float angle = world->player_a - player_fov/2 + player_fov*r/512;      
      //Pour regler la fluidité des fps, modifier l'incrementation de t, .001 => 30 fps, .002 => 60 fps, .05 => 144 fps 
  		for (float t=0; t<20; t+=.002) {
      		float cx = world->player_x + t*cos(angle);
      		float cy = world->player_y + t*sin(angle);

        	if (map[(int)(cy)][(int)(cx)]!=' '){
        			int line_height = HEIGHT/t;
		  		for (int i = 0; i < 15; i++){
		  			SDL_RenderDrawLine(screen->renderer, r*2.5+i , (HEIGHT+line_height)/2, r*2.5+i, (HEIGHT-line_height)/2);
		  		}
        			break;
      		}
    	}
  	}
  drawFPS(world, screen);
  drawMiniMap(screen, world);
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

void drawGround(screen_t* screen, world_t* world){
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = world->player_a*800;
  srcRect.y = 0; //0
  srcRect.w = 1280;
  srcRect.h = 720/2;

  destRect.x = 0;  //0
  destRect.y = 720/2-80; //720/2-80
  destRect.w = 1280;  //1280
  destRect.h = 720-250;  //720-250

  SDL_RenderCopy(screen->renderer, screen->groundTexture, &srcRect, &destRect);
}