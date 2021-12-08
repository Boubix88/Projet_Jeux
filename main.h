#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "renderer.h"
#include <stdbool.h>

typedef struct world_s
{
    float player_a;
    float player_x;
    float player_y;
    bool exit; 

}world_t;

void handle_events(SDL_Event *event, world_t *world);

void draw3DMapSdl(const char map[16][16], screen_t* screen, world_t *world);
void map(screen_t* screen, world_t *world);