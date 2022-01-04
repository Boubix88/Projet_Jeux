#include "main.h"

int main(void) {
    screen_t screen;
    world_t world;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    Init_Screen(&screen);
    initialiserTexture(&screen);
    intitialiserData(&world);
    initialiserTextureMenuStart(&screen);
    SDL_Delay(100);

    testSourisMenuStart(&event, &screen, &world);
    setMonstre(&world);
    destroyTexturesMenuStart(&screen);

    SDL_ShowCursor(SDL_FALSE);

    while (!world.exit) {
        world.ancienPlayer_x = world.player_x; //Pour les collisions
        world.ancienPlayer_y = world.player_y;
        draw3DMapSdl(&screen, &world);
        handle_events(&event, &world, &screen);
        calculFPS(&world);
        testCollision(&world);
        SDL_WarpMouseInWindow(screen.window, 1280 / 2, 720 / 2);
    }

    ecrireScore(&world);
    TTF_Quit();
    SDL_Quit();
    destroyTextures(&screen);
    SDL_DestroyRenderer(screen.renderer);
    SDL_DestroyWindow(screen.window);
    return EXIT_SUCCESS;
}