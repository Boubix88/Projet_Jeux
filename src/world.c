#include "main.h"

void calculFPS(world_t* world){
    world->fps_frames++;
    if (world->fps_lasttime < SDL_GetTicks() - FPS_INTERVAL*1000)
    {
        world->fps_lasttime = SDL_GetTicks();
        world->fps_current = world->fps_frames;
        world->fps_frames = 0;
    }
}