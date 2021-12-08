#include "main.h"

int main(int argc, char *argv[]){
    screen_t screen;
    world_t world;
    SDL_Event event;
    SDL_Init(SDL_INIT_VIDEO);
    Init_Screen(&screen);

    world.player_a = 1.8;
    world.player_x = 5;
    world.player_y = 6;
    world.exit = false;


    while (!world.exit){
        map(&screen, &world);
        handle_events(&event, &world);
    }
    SDL_Delay(2000);

    SDL_Quit();
    SDL_DestroyWindow(screen.window);
    return EXIT_SUCCESS;
}