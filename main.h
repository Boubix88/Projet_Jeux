#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "renderer.h"
#include <stdbool.h>
#include <SDL_ttf.h>


typedef struct world_s
{
    float player_a;
    float player_x;
    float player_y;
    bool exit; 
    float vx;       //coordonnée du point x pour se déplacer
    float vy;       //coordonnée du point y pour se déplacer
    float dis;

    Uint32 fps_lasttime; //the last recorded time.
    Uint32 fps_current; //the current FPS.
    Uint32 fps_frames; //frames passed since the last recorded fps.

}world_t;

void handle_events(SDL_Event *event, world_t *world, screen_t *screen);

void draw3DMapSdl(const char map[16][16], screen_t* screen, world_t *world);
void map(screen_t* screen, world_t *world);
void drawSky(screen_t* screen, world_t* world);
void drawGround(screen_t* screen, world_t* world);
void calculFPS(world_t* world);
void drawFPS(world_t* world, screen_t* screen);
void initialiserTexture(screen_t* screen);

void drawMiniMap(screen_t* screen, world_t* world);
void drawWalls(const char map[16][16], screen_t *screen);
void drawPlayer(screen_t* screen, world_t* world);
void drawFov(const char map[16][16], screen_t* screen, world_t* world);
void deplacement(world_t*world);
void avancerDirection(world_t* world);
