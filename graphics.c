#include "main.h"

void initialiserTexture(screen_t* screen){
    screen->sky = SDL_LoadBMP("ciel.bmp");
    screen->skyTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->sky);
    SDL_FreeSurface(screen->sky);

    screen->ground = SDL_LoadBMP("beton.bmp");
    screen->groundTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->ground);
    SDL_FreeSurface(screen->ground);
}

void drawFPS(world_t* world, screen_t* screen){
    SDL_Color color = {255, 0, 100, 255};
    SDL_Surface *textSurface = TTF_RenderText_Solid(screen->font, "FPS  ", color);
    SDL_Texture *text = SDL_CreateTextureFromSurface(screen->renderer, textSurface);
    SDL_Rect textRect;
    textRect.x = 2;
    textRect.y = 0;
    textRect.h = 35;
    textRect.w = 50;
    SDL_RenderCopy(screen->renderer, text, NULL, &textRect);


    char fps[5];
    sprintf(fps,"%d", world->fps_current);

    SDL_Surface *fpsSurface = TTF_RenderText_Solid(screen->font, fps, color);
    SDL_Texture *fpsTexture = SDL_CreateTextureFromSurface(screen->renderer, fpsSurface);
    SDL_Rect fpsRect;
    fpsRect.x = 50;
    fpsRect.y = 0;
    fpsRect.h = 35;
    fpsRect.w = 20;
    SDL_RenderCopy(screen->renderer, fpsTexture, NULL, &fpsRect);

    SDL_FreeSurface(textSurface);
    SDL_FreeSurface(fpsSurface);
}