#include <SDL2/SDL.h>
#include "renderer.h"
#include"main.h"


void Init_Screen(screen_t* screen) {
    screen->window = SDL_CreateWindow("Prison Survival", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_RESIZABLE);
    screen->icon = SDL_LoadBMP("logo_prison.bmp");
    SDL_SetWindowIcon(screen->window, screen->icon);
    screen->renderer = SDL_CreateRenderer(screen->window, -1, 0);
}/*
void draw3DMap2(screen_t* screen, const char map[16][16]) {
    float player_x = 5;
    float player_y = 6;
    float player_a = 1.8;
    float player_fov = 1.58;

    for (int i = 0; i < 100; i++) {
        SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, 0);
        SDL_RenderClear(screen->renderer);
        SDL_SetRenderDrawColor(screen->renderer, 120, 24, 0, 1);

       for (int r = 0; r < 512; r++) {
            float angle = player_a - player_fov / 2 + player_fov * r / 512;
            for (float t = 0; t < 20; t += .05) {
                float cx = player_x + t * cos(angle);
                float cy = player_y + t * sin(angle);

                if (map[(int)(cy)][(int)(cx)] != ' ') {
                    int line_height = HEIGHT / t;
                    for (int i = 0; i < 15; i++) {
                        SDL_RenderDrawLine(screen->renderer, r * 2.5 + i, (720 + line_height) / 2 , r * 2.5 + i, (720 - line_height)/2);
                        }
                    break;
                }
            }
        }
    player_a +=0.02;
    SDL_RenderPresent(screen->renderer);

    }



}*/