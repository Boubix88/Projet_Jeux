#include"main.h"


void Init_Screen(screen_t* screen) {
    screen->window = SDL_CreateWindow("Prison Survival", 200, 200, 1280, 720, SDL_WINDOW_RESIZABLE);
    screen->icon = SDL_LoadBMP("../ressources/logo_prison.bmp");
    SDL_SetWindowIcon(screen->window, screen->icon);
    screen->renderer = SDL_CreateRenderer(screen->window, -1, 0);
}