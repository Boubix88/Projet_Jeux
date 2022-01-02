#include "main.h"

void initialiserTexture(screen_t* screen){
    screen->font = TTF_OpenFont("../ressources/Pixeled.ttf", 25);
    if (screen->font == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }

    screen->sky = SDL_LoadBMP("../ressources/ciel.bmp");
    if (screen->sky == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->skyTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->sky);
    SDL_FreeSurface(screen->sky);

    screen->ground = SDL_LoadBMP("../ressources/solgris.bmp");
    if (screen->ground == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->groundTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->ground);
    SDL_FreeSurface(screen->ground);  

    screen->murBrique = SDL_LoadBMP("../ressources/mur_brique.bmp");
    if (screen->murBrique == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->murBriqueTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->murBrique);
    SDL_FreeSurface(screen->murBrique);

    screen->degrade = SDL_LoadBMP("../ressources/degrade.bmp");
    if (screen->degrade == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->degradeTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->degrade);
    SDL_FreeSurface(screen->degrade);

    screen->pistolet = SDL_LoadBMP("../ressources/sprite_pistolet.bmp");
    if (screen->pistolet == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->pistoletTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->pistolet);
    SDL_FreeSurface(screen->pistolet);

    screen->ammo = SDL_LoadBMP("../ressources/sprite_ammo.bmp");
    if (screen->ammo == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->ammoTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->ammo);
    SDL_FreeSurface(screen->ammo);
}

void initialiserTexturesMenu(screen_t* screen){
    screen->menu = SDL_LoadBMP("../ressources/flou.bmp");
    if (screen->menu == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->menuTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->menu);
    SDL_FreeSurface(screen->menu);

    screen->continuerS = SDL_LoadBMP("../ressources/continuer.bmp");
    if (screen->continuerS == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->continuerTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->continuerS);
    SDL_FreeSurface(screen->continuerS);

    screen->graphismes = SDL_LoadBMP("../ressources/graphismes.bmp");
    if (screen->graphismes == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->graphismesTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->graphismes);
    SDL_FreeSurface(screen->graphismes);

    screen->quitter = SDL_LoadBMP("../ressources/quitter.bmp");
    if (screen->quitter == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->quitterTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->quitter);
    SDL_FreeSurface(screen->quitter);

    screen->flou = SDL_LoadBMP("../ressources/flou_ecriture.bmp");
    if (screen->flou == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->flouTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->flou);
    SDL_FreeSurface(screen->flou); 
    screen->robot = SDL_LoadBMP("../ressources/robot_bmp.bmp");
    if (screen->robot == NULL) {
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->robotTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->robot);
    SDL_FreeSurface(screen->robot);
}


void destroyTexturesMenu(screen_t* screen){
    SDL_DestroyTexture(screen->menuTexture);
    SDL_DestroyTexture(screen->continuerTexture);
    SDL_DestroyTexture(screen->graphismesTexture);
    SDL_DestroyTexture(screen->quitterTexture);
    SDL_DestroyTexture(screen->flouTexture);
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
    SDL_RenderCopy(screen->renderer, screen->menuTexture, NULL, NULL);
    SDL_RenderPresent(screen->renderer);
}

void applyMenuOption(screen_t* screen){
    int x, y;

    SDL_GetMouseState(&x, &y);
    SDL_Rect destRect;

    if (x >= 461 && x <= 808 && y >= 152 && y <= 201){
        destRect.x = 458;
        destRect.y = 145;
        destRect.w = 352;
        destRect.h = 60;
        SDL_RenderCopy(screen->renderer, screen->continuerTexture, NULL, &destRect);
    }
    else if (x >= 428 && x <= 854 && y >= 305 && y <= 366){
        destRect.x = 426;
        destRect.y = 300;
        destRect.w = 431;
        destRect.h = 71;
        SDL_RenderCopy(screen->renderer, screen->graphismesTexture, NULL, &destRect);
    }
    else if (x >= 524 && x <= 759 && y >= 464 && y <= 521){
        destRect.x = 521;
        destRect.y = 457;
        destRect.w = 242;
        destRect.h = 70;
        SDL_RenderCopy(screen->renderer, screen->quitterTexture, NULL, &destRect);   
    }else {
        SDL_RenderCopy(screen->renderer, screen->flouTexture, NULL, NULL);   
    }
    SDL_RenderPresent(screen->renderer);
}

void applyCrosshair(screen_t* screen){
    screen->crosshair = SDL_LoadBMP("../ressources/crosshair.bmp");
    screen->crosshairTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->crosshair);

    SDL_Rect destRect;
    destRect.x = 635;
    destRect.y = 355;
    destRect.w = 10;
    destRect.h = 10;

    SDL_RenderCopy(screen->renderer, screen->crosshairTexture, NULL, &destRect);
    SDL_FreeSurface(screen->crosshair);
}

void applyPistolet(screen_t* screen){
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 8;
    srcRect.y = 29;
    srcRect.w = 111;
    srcRect.h = 93;

    destRect.x = 1280/2;
    destRect.y = 720-279;
    destRect.w = 333;
    destRect.h = 279;

    SDL_RenderCopy(screen->renderer, screen->pistoletTexture, &srcRect, &destRect);
}

void applyTirPistolet(screen_t* screen){
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 119;
    srcRect.y = 6;
    srcRect.w = 125;
    srcRect.h = 122;

    destRect.x = 1280/2;
    destRect.y = 720-366;
    destRect.w = 375;
    destRect.h = 366;

    SDL_RenderCopy(screen->renderer, screen->pistoletTexture, &srcRect, &destRect);
}

void applyViseeFpsPistolet(screen_t* screen){
    SDL_Rect srcRect1;
    SDL_Rect destRect1;

    srcRect1.x = 175;  // Image 2
    srcRect1.y = 373;
    srcRect1.w = 152;
    srcRect1.h = 155;

    destRect1.x = 1280/2 - 163; // Image 2
    destRect1.y = 720-385;
    destRect1.w = 380;
    destRect1.h = 387;
    
    SDL_RenderCopy(screen->renderer, screen->pistoletTexture, &srcRect1, &destRect1);
}

void applyTirPistoletFps(screen_t* screen){
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = 327;
    srcRect.y = 340;
    srcRect.w = 196;
    srcRect.h = 203;

    destRect.x = 1280/2 - 210;
    destRect.y = 720-507;
    destRect.w = 490;
    destRect.h = 507;

    SDL_RenderCopy(screen->renderer, screen->pistoletTexture, &srcRect, &destRect);
}

void drawAmmo(screen_t* screen, world_t* world){
    SDL_Rect destRect;

    destRect.x = world->ammo.x;
    destRect.y = world->ammo.y;
    destRect.w = world->ammo.w;
    destRect.h = world->ammo.h;

    SDL_RenderCopy(screen->renderer, screen->ammoTexture, NULL, &destRect);
}

