#include "main.h"

void initialiserTexture(screen_t* screen){
    screen->sky = SDL_LoadBMP("../ressources/ciel.bmp");
    screen->skyTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->sky);
    SDL_FreeSurface(screen->sky);

    screen->ground = SDL_LoadBMP("../ressources/beton.bmp");
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

void apply_menu(screen_t* screen){
    screen->menu = SDL_LoadBMP("../ressources/Flou.bmp");
    screen->menuTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->menu);
    SDL_RenderCopy(screen->renderer, screen->menuTexture, NULL, NULL);
    SDL_RenderPresent(screen->renderer);
    SDL_FreeSurface(screen->menu);
}

void applyMenuOption(screen_t* screen){
    int x, y;
    SDL_Surface* continuerS = SDL_LoadBMP("../ressources/continuer.bmp");
    SDL_Texture* continuerTexture = SDL_CreateTextureFromSurface(screen->renderer, continuerS);
    SDL_Surface* graphismes = SDL_LoadBMP("../ressources/graphismes.bmp");
    SDL_Texture* graphismesTexture = SDL_CreateTextureFromSurface(screen->renderer, graphismes);
    SDL_Surface* quitter = SDL_LoadBMP("../ressources/quitter.bmp");
    SDL_Texture* quitterTexture = SDL_CreateTextureFromSurface(screen->renderer, quitter);
    SDL_Surface* flou = SDL_LoadBMP("../ressources/flou_ecriture.bmp");
    SDL_Texture* flouTexture = SDL_CreateTextureFromSurface(screen->renderer, flou);

    SDL_FreeSurface(continuerS);
    SDL_FreeSurface(graphismes);
    SDL_FreeSurface(quitter);
    SDL_FreeSurface(flou);

    SDL_GetMouseState(&x, &y);
    SDL_Rect destRect;

    if (x >= 461 && x <= 808 && y >= 152 && y <= 201){
        destRect.x = 458;
        destRect.y = 145;
        destRect.w = 352;
        destRect.h = 60;
        SDL_RenderCopy(screen->renderer, continuerTexture, NULL, &destRect);
    }
    else if (x >= 428 && x <= 854 && y >= 305 && y <= 366){
        destRect.x = 426;
        destRect.y = 300;
        destRect.w = 431;
        destRect.h = 71;
        SDL_RenderCopy(screen->renderer, graphismesTexture, NULL, &destRect);
    }
    else if (x >= 524 && x <= 759 && y >= 464 && y <= 521){
        destRect.x = 521;
        destRect.y = 457;
        destRect.w = 242;
        destRect.h = 70;
        SDL_RenderCopy(screen->renderer, quitterTexture, NULL, &destRect);   
    }else {
        SDL_RenderCopy(screen->renderer, flouTexture, NULL, NULL);   
    }
    SDL_RenderPresent(screen->renderer);
}