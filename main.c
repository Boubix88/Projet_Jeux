#include "main.h"

int main(int argc, char *argv[]){
    screen_t screen;
    world_t world;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    Init_Screen(&screen);

    world.player_a = 1.8;
    world.player_x = 5;
    world.player_y = 6;
    world.exit = false;

    initialiserTexture(&screen);

    screen.font = TTF_OpenFont("Pixeled.ttf",25);
    
    world.fps_lasttime = SDL_GetTicks(); //the last recorded time.
    world.fps_current; //the current FPS.
    world.fps_frames = 0; //frames passed since the last recorded fps.

    while (!world.exit){
        //SDL_WarpMouseInWindow(screen.window, world.player_a, 720/2);

        map(&screen, &world);
        handle_events(&event, &world, &screen);
        calculFPS(&world);
    }
    SDL_Delay(2000);

    TTF_Quit();
    SDL_Quit();
    SDL_DestroyWindow(screen.window);
    return EXIT_SUCCESS;
}