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

    SDL_Surface* murBrique = SDL_LoadBMP("../ressources/mur_brique.bmp");
    if (murBrique == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->murBriqueTexture = SDL_CreateTextureFromSurface(screen->renderer, murBrique);
    SDL_FreeSurface(murBrique);

    SDL_Surface* barreauPorte = SDL_LoadBMP("../ressources/barreauPorte.bmp");
    if (barreauPorte == NULL) {
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->barreauPorteTexture = SDL_CreateTextureFromSurface(screen->renderer, barreauPorte);
    SDL_FreeSurface(barreauPorte);


    SDL_Surface* policierGarde = SDL_LoadBMP("../ressources/policierGarde.bmp");
    if (policierGarde == NULL) {
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->policierGardeTexture = SDL_CreateTextureFromSurface(screen->renderer, policierGarde);
    SDL_FreeSurface(policierGarde);





    SDL_Surface* tonyLeMechant = SDL_LoadBMP("../ressources/tonyLeMechant.bmp");
    if (tonyLeMechant == NULL) {
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->tonyLeMechantTexture = SDL_CreateTextureFromSurface(screen->renderer, tonyLeMechant);
    SDL_FreeSurface(tonyLeMechant);




    screen->degrade = SDL_LoadBMP("../ressources/degrade.bmp");
    if (screen->degrade == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->degradeTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->degrade);
    SDL_FreeSurface(screen->degrade);

    SDL_Surface* pistolet = SDL_LoadBMP("../ressources/sprite_pistolet.bmp");
    if (pistolet == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->pistoletTexture = SDL_CreateTextureFromSurface(screen->renderer, pistolet);
    SDL_FreeSurface(pistolet);

    SDL_Surface* ammo = SDL_LoadBMP("../ressources/sprite_ammo.bmp");
    if (ammo == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->ammoTexture = SDL_CreateTextureFromSurface(screen->renderer, ammo);
    SDL_FreeSurface(ammo);

    SDL_Surface* robot = SDL_LoadBMP("../ressources/robot.bmp");
    if (robot == NULL) {
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->robotTexture = SDL_CreateTextureFromSurface(screen->renderer, robot);
    SDL_FreeSurface(robot);

    SDL_Surface* murCellule = SDL_LoadBMP("../ressources/cellule_prison.bmp");
    if (murCellule == NULL) {
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->murCellulePrison = SDL_CreateTextureFromSurface(screen->renderer, murCellule);
    SDL_FreeSurface(murCellule);


    SDL_Surface* exitDoor = SDL_LoadBMP("../ressources/exitDoor.bmp");
    if (exitDoor == NULL) {
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->exitDoorTexture = SDL_CreateTextureFromSurface(screen->renderer, exitDoor);
    SDL_FreeSurface(exitDoor);


    SDL_Surface* impactAmmo = SDL_LoadBMP("../ressources/impact_ammo.bmp");
    if (impactAmmo == NULL) {
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->impactAmmoTexture = SDL_CreateTextureFromSurface(screen->renderer, impactAmmo);
    SDL_FreeSurface(impactAmmo);
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
}

void initialiserTexturesMenuGraphisme(screen_t* screen){
    SDL_Surface* menu = SDL_LoadBMP("../ressources/menu_graphisme.bmp");
    if (menu == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->menuGraphisme = SDL_CreateTextureFromSurface(screen->renderer, menu);
    SDL_FreeSurface(menu); 

    SDL_Surface* tres_haut = SDL_LoadBMP("../ressources/tres_haut.bmp");
    if (tres_haut == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->tresHautGraphisme = SDL_CreateTextureFromSurface(screen->renderer, tres_haut);
    SDL_FreeSurface(tres_haut); 

    SDL_Surface* haut = SDL_LoadBMP("../ressources/haut.bmp");
    if (haut == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->hautGraphisme = SDL_CreateTextureFromSurface(screen->renderer, haut);
    SDL_FreeSurface(haut); 

    SDL_Surface* normal = SDL_LoadBMP("../ressources/normal.bmp");
    if (normal == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->normalGraphisme = SDL_CreateTextureFromSurface(screen->renderer, normal);
    SDL_FreeSurface(normal); 

    SDL_Surface* bas = SDL_LoadBMP("../ressources/bas.bmp");
    if (bas == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->basGraphisme = SDL_CreateTextureFromSurface(screen->renderer, bas);
    SDL_FreeSurface(bas); 

    SDL_Surface* tres_bas = SDL_LoadBMP("../ressources/tres_bas.bmp");
    if (tres_bas == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->tresBasGraphisme = SDL_CreateTextureFromSurface(screen->renderer, tres_bas);
    SDL_FreeSurface(tres_bas); 
}

void initialiserTextureMenuStart(screen_t* screen){
    SDL_Surface* menu = SDL_LoadBMP("../ressources/start_menu.bmp");
    if (menu == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->menuStartTexture = SDL_CreateTextureFromSurface(screen->renderer, menu);
    SDL_FreeSurface(menu); 

    SDL_Surface* start = SDL_LoadBMP("../ressources/start.bmp");
    if (start == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->startTexture = SDL_CreateTextureFromSurface(screen->renderer, start);
    SDL_FreeSurface(start); 

    SDL_Surface* moins = SDL_LoadBMP("../ressources/moins.bmp");
    if (moins == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->moinsTexture = SDL_CreateTextureFromSurface(screen->renderer, moins);
    SDL_FreeSurface(moins); 

    SDL_Surface* plus = SDL_LoadBMP("../ressources/plus.bmp");
    if (plus == NULL){
        printf("Erreur SDL2 : %s", SDL_GetError());
    }
    screen->plusTexture = SDL_CreateTextureFromSurface(screen->renderer, plus);
    SDL_FreeSurface(plus);
}

void destroyTexturesMenu(screen_t* screen){
    SDL_DestroyTexture(screen->menuTexture);
    SDL_DestroyTexture(screen->continuerTexture);
    SDL_DestroyTexture(screen->graphismesTexture);
    SDL_DestroyTexture(screen->quitterTexture);
    SDL_DestroyTexture(screen->flouTexture);

    SDL_DestroyTexture(screen->menuGraphisme);
    SDL_DestroyTexture(screen->tresHautGraphisme);
    SDL_DestroyTexture(screen->hautGraphisme);
    SDL_DestroyTexture(screen->normalGraphisme);
    SDL_DestroyTexture(screen->basGraphisme);
    SDL_DestroyTexture(screen->tresBasGraphisme);
}


void drawFPS(world_t* world, screen_t* screen){
    SDL_Color color = {255, 0, 100, 255};
    screen->textSurface = TTF_RenderText_Solid(screen->font, "FPS  ", color);
    screen->text = SDL_CreateTextureFromSurface(screen->renderer, screen->textSurface);
    SDL_Rect textRect;
    textRect.x = 2;
    textRect.y = 0;
    textRect.h = 35;
    textRect.w = 50;
    SDL_RenderCopy(screen->renderer, screen->text, NULL, &textRect);


    char fps[5];
    sprintf(fps,"%d", world->fps_current);

    screen->fpsSurface = TTF_RenderText_Solid(screen->font, fps, color);
    screen->fpsTexture = SDL_CreateTextureFromSurface(screen->renderer, screen->fpsSurface);
    SDL_Rect fpsRect;
    fpsRect.x = 50;
    fpsRect.y = 0;
    fpsRect.h = 35;
    fpsRect.w = 20;
    SDL_RenderCopy(screen->renderer, screen->fpsTexture, NULL, &fpsRect);

    SDL_FreeSurface(screen->textSurface);
    SDL_FreeSurface(screen->fpsSurface);
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

void applyMenuGraphismeOption(screen_t* screen){
    int x, y;

    SDL_GetMouseState(&x, &y);
    SDL_Rect destRect;

    if (x >= 5 && x <= 333 && y >= 129 && y <= 176){
        destRect.x = 4;
        destRect.y = 111;
        destRect.w = 332;
        destRect.h = 67;
        SDL_RenderCopy(screen->renderer, screen->tresHautGraphisme, NULL, &destRect);
    }
    else if (x >= 7 && x <= 166 && y >= 223 && y <= 270){
        destRect.x = 1;
        destRect.y = 210;
        destRect.w = 168;
        destRect.h = 62;
        SDL_RenderCopy(screen->renderer, screen->hautGraphisme, NULL, &destRect);
    }
    else if (x >= 7 && x <= 251 && y >= 315 && y <= 361){
        destRect.x = 1;
        destRect.y = 302;
        destRect.w = 252;
        destRect.h = 60;
        SDL_RenderCopy(screen->renderer, screen->normalGraphisme, NULL, &destRect);   
    }else if (x >= 7 && x <= 125 && y >= 415 && y <= 462){
        destRect.x = 1;
        destRect.y = 402;
        destRect.w = 132;
        destRect.h = 62;
        SDL_RenderCopy(screen->renderer, screen->basGraphisme, NULL, &destRect);   
    }else if (x >= 6 && x <= 297 && y >= 512 && y <= 560){
        destRect.x = 5;
        destRect.y = 494;
        destRect.w = 295;
        destRect.h = 67;
        SDL_RenderCopy(screen->renderer, screen->tresBasGraphisme, NULL, &destRect);   
    }else {
        SDL_RenderCopy(screen->renderer, screen->menuGraphisme, NULL, NULL);   
    }
    SDL_RenderPresent(screen->renderer);
}

void applyMenuGraphisme(screen_t* screen){
    SDL_RenderCopy(screen->renderer, screen->menuGraphisme, NULL, NULL);
    SDL_RenderPresent(screen->renderer);
}

void applyCrosshair(screen_t* screen){
    SDL_Surface* crosshair = SDL_LoadBMP("../ressources/crosshair.bmp");
    screen->crosshairTexture = SDL_CreateTextureFromSurface(screen->renderer, crosshair);

    SDL_Rect destRect;
    destRect.x = 635;
    destRect.y = 355;
    destRect.w = 10;
    destRect.h = 10;

    SDL_RenderCopy(screen->renderer, screen->crosshairTexture, NULL, &destRect);
    SDL_FreeSurface(crosshair);
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

void drawExplosion(screen_t* screen, world_t* world) {
    if (world->ammo.x <= SCREEN_WIDTH / 2 + 7 && world->ammo.y <= SCREEN_HEIGHT / 2 + 7 && world->compteurNbreImpact != 4) {
        SDL_Rect destRect;
        destRect.x = SCREEN_WIDTH / 2 - ((50 / 4) * world->compteurNbreImpact) / 2;
        destRect.y = SCREEN_HEIGHT / 2 - ((41 / 4) * world->compteurNbreImpact) / 2;
        destRect.w = (50 / 4) * world->compteurNbreImpact;
        destRect.h = (41 / 4) * world->compteurNbreImpact;

        world->compteurNbreImpact++;

        SDL_RenderCopy(screen->renderer, screen->impactAmmoTexture, NULL, &destRect);
    }
}

void applyMenuStart(screen_t* screen){
    SDL_RenderCopy(screen->renderer, screen->menuStartTexture, NULL, NULL);
}

void drawDifficulte(screen_t* screen, world_t* world){
    SDL_Color color = {255, 0, 100, 255};
    SDL_Rect textRect;

    textRect.x = SCREEN_WIDTH/2 - 50/2 ;
    textRect.y = SCREEN_HEIGHT/2 - 100;
    textRect.h = 70;
    textRect.w = 40;

    char difficulte[3];
    sprintf(difficulte,"%d", world->difficulte);

    SDL_Surface* text = TTF_RenderText_Solid(screen->font, difficulte, color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(screen->renderer, text);

    SDL_RenderCopy(screen->renderer, textTexture, NULL, &textRect);

    SDL_FreeSurface(text);
    SDL_DestroyTexture(textTexture);
}

void applyStart(screen_t* screen){
    SDL_Rect destRect;

    destRect.x = 505;
    destRect.y = 488;
    destRect.w = 250;
    destRect.h = 90;

    SDL_RenderCopy(screen->renderer, screen->startTexture, NULL, &destRect);
}

void applyMoins(screen_t* screen){
    SDL_Rect destRect;

    destRect.x = 414;
    destRect.y = 360;
    destRect.w = 24;
    destRect.h = 8;

    SDL_RenderCopy(screen->renderer, screen->moinsTexture, NULL, &destRect);
}

void applyPlus(screen_t* screen){
    SDL_Rect destRect;

    destRect.x = 849;
    destRect.y = 352;
    destRect.w = 27;
    destRect.h = 25;

    SDL_RenderCopy(screen->renderer, screen->plusTexture, NULL, &destRect);
}

void destroyTexturesMenuStart(screen_t* screen){
    SDL_DestroyTexture(screen->menuStartTexture);
    SDL_DestroyTexture(screen->startTexture);
    SDL_DestroyTexture(screen->moinsTexture);
    SDL_DestroyTexture(screen->plusTexture);
}

void destroyTextures(screen_t* screen){
    SDL_DestroyTexture(screen->text);
    SDL_DestroyTexture(screen->fpsTexture);

    SDL_DestroyTexture(screen->skyTexture);
    SDL_DestroyTexture(screen->groundTexture);
    SDL_DestroyTexture(screen->degradeTexture);
    SDL_DestroyTexture(screen->crosshairTexture);
    SDL_DestroyTexture(screen->pistoletTexture);
    SDL_DestroyTexture(screen->ammoTexture);
    SDL_DestroyTexture(screen->murBriqueTexture);
    SDL_DestroyTexture(screen->murCellulePrison);
    SDL_DestroyTexture(screen->robotTexture);
    SDL_DestroyTexture(screen->impactAmmoTexture);
    SDL_DestroyTexture(screen->exitDoorTexture);
    SDL_DestroyTexture(screen->barreauPorteTexture);
    SDL_DestroyTexture(screen->policierGardeTexture);
    SDL_DestroyTexture(screen->tonyLeMechantTexture);
}