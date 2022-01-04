#include "main.h"


void handle_events(SDL_Event *event, world_t *world, screen_t *screen){
    
    while(SDL_PollEvent(event)){
        switch(event->type) {
            //si une touche est appuyée
            case SDL_QUIT :
                world->exit = true;
            break;

            case SDL_KEYDOWN :
                //si la touche appuyée est 'D' 
                if(event->key.keysym.sym == SDLK_d || event->key.keysym.sym == SDLK_RIGHT){
                    world->angle += M_PI / 2;
                    avancerDirection(world);
                    world->player_x += world->vx * MOVING_STEP;
                    world->player_y += world->vy * MOVING_STEP;
                    world->angle -= M_PI / 2;
                    avancerDirection(world);
                }
                if (event->key.keysym.sym == SDLK_l && world->tonyMort && world->objectif) {
                    world->exit = true;
                }

                //si la touche appuyée est 'Q'
                if (event->key.keysym.sym == SDLK_q || event->key.keysym.sym ==SDLK_LEFT){
                    world->angle += M_PI / 2;
                    avancerDirection(world);
                    world->player_x -= world->vx * MOVING_STEP;
                    world->player_y -= world->vy * MOVING_STEP;
                    world->angle -= M_PI / 2;
                    avancerDirection(world);
                }
                //si la touche appuyée est 'Haut' ou 'Z'
                if (event->key.keysym.sym == SDLK_z || event->key.keysym.sym ==SDLK_UP){
                    world->player_x += world->vx * MOVING_STEP;
                    world->player_y += world->vy * MOVING_STEP;
                }
                //si la touche appuyée est 'Bas' ou 'S'
                if (event->key.keysym.sym == SDLK_s || event->key.keysym.sym ==SDLK_DOWN){
                    world->player_x -= world->vx * MOVING_STEP;
                    world->player_y -= world->vy * MOVING_STEP;
                }
                //si la touche appuyée est 'Echap'
                if (event->key.keysym.sym == SDLK_ESCAPE){
                    SDL_ShowCursor(SDL_TRUE);
                    initialiserTexturesMenu(screen);
                    initialiserTexturesMenuGraphisme(screen);
                    apply_menu(screen);
                    testSourisPosition(event, screen, world);
                    destroyTexturesMenu(screen);
                }
            break;

            case SDL_MOUSEBUTTONDOWN :
                switch (event->button.button){
                    case SDL_BUTTON_LEFT:
                        if (world->fpsView == false){
                            //applyViseeFpsPistolet(screen);
                            applyTirPistolet(screen);
                            if (!world->ammoShooted){
                                drawAmmo(screen, world);
                                world->ammoShooted = true;
                                world->ammo.direction = 0;
                                world->ammo.xMap = world->player_x;
                                world->ammo.yMap = world->player_y;
                            }
                            SDL_RenderPresent(screen->renderer);
                        }else if(world->fpsView){
                            if (!world->ammoShooted) {
                                world->ammoShooted = true;
                                world->ammo.direction = 0;
                                world->ammo.xMap = world->player_x;
                                world->ammo.yMap = world->player_y;
                            }
                            applyTirPistoletFps(screen);
                            SDL_RenderPresent(screen->renderer);
                        }
                    break;

                    case SDL_BUTTON_RIGHT:
                        //applyViseeFpsPistolet(screen);
                        if (world->fpsView){
                            world->fpsView = false;
                        }else {
                            world->fpsView = true;
                        }                      
                    break;
                }
            break;

            case SDL_MOUSEMOTION :
                if (event->motion.xrel > 0){
                    world->player_a += .007;
                }
                else{
                    world->player_a -= .007;
                }
                world->angle = world->player_a;
                avancerDirection(world);
            break;
        }
    }
    SDL_ShowCursor(SDL_FALSE);

}

void testSourisPosition(SDL_Event* event, screen_t* screen,world_t* world){
    bool continuer = false;
    int x, y;
    while (!continuer){
        //Applique les couleurs des options selon la position de la souris
        applyMenuOption(screen);
        if (world->graphisme){
            applyMenuGraphismeOption(screen);
        }
        while(SDL_PollEvent(event)){
            switch(event->type) {
                case SDL_MOUSEBUTTONDOWN :
                    SDL_GetMouseState(&x, &y);
                    if (x >= 461 && x <= 808 && y >= 152 && y <= 201){
                        //Continuer, on continue
                        world->graphisme = false;
                        continuer = true;

                        world->fps_lasttime = SDL_GetTicks(); //Le dernier temps enregistré
                        world->fps_frames = 0; //Le nombre d'images depuis le dernier FPS
                        world->fps_current = 0; //Les FPS du moment
                    }
                    else if (x >= 428 && x <= 854 && y >= 305 && y <= 366){
                        //Graphismes, pour l'instant on continue
                        world->graphisme = true;
                        applyMenuGraphisme(screen);
                    }
                    else if (x >= 524 && x <= 759 && y >= 464 && y <= 521){
                        //Quitter
                        world->exit = true;
                        continuer = true;    
                    }
                    if (world->graphisme){
                        if (x >= 5 && x <= 333 && y >= 129 && y <= 176){
                            //Tres haut
                            world->graphismeOption = .002;
                            world->graphismeOptionRayon = 512;
                            world->graphismeOptionWidth = 1;
                        }else if (x >= 7 && x <= 166 && y >= 223 && y <= 270){
                            //Haut
                            world->graphismeOption = .005;
                            world->graphismeOptionRayon = 512;
                            world->graphismeOptionWidth = 1;
                        }else if (x >= 7 && x <= 251 && y >= 315 && y <= 361){
                            //Normal
                            world->graphismeOption = .01;
                            world->graphismeOptionRayon = 256;
                            world->graphismeOptionWidth = 2;
                        }else if (x >= 7 && x <= 125 && y >= 415 && y <= 462){
                            //Bas
                            world->graphismeOption = .05;
                            world->graphismeOptionRayon = 256;
                            world->graphismeOptionWidth = 2;
                        }else if (x >= 6 && x <= 297 && y >= 512 && y <= 560){
                            //Tres bas
                            world->graphismeOption = .08;
                            world->graphismeOptionRayon = 128;
                            world->graphismeOptionWidth = 4;
                        }
                    }
                break;
            }
        }

    }
}

void testSourisMenuStart(SDL_Event* event, screen_t* screen, world_t* world){
    int x, y;
    applyMenuStart(screen);
    while (!world->continuer){
        //Applique les couleurs des options selon la position de la souris
        testPositionSourisMenuStart(screen, world);

        while(SDL_PollEvent(event)){
            switch(event->type) {
                case SDL_MOUSEBUTTONDOWN :
                    SDL_GetMouseState(&x, &y);
                    if (x >= 393 && x <= 447 && y >= 325 && y <= 401){
                        //Moins -
                        if (world->difficulte != 0){
                            world->difficulte --;
                        }
                    }
                    if (x >= 839 && x <= 892 && y >= 325 && y <= 401){
                        //Plus +
                        if (world->difficulte < MAX_SPRITE){
                            world->difficulte ++;
                        }
                    }
                    else if (x >= 503 && x <= 756 && y >= 486 && y <= 578){
                        //Start
                        world->continuer = true;
                    }
                break;

                case SDL_KEYDOWN :
                    //si la touche appuyée est 'Echap'
                    if (event->key.keysym.sym == SDLK_ESCAPE){
                        world->continuer = true;
                        world->exit = true;
                    }
                break;
            }
        }
    }
}

void testPositionSourisMenuStart(screen_t* screen, world_t* world){
    int x, y;
    SDL_GetMouseState(&x, &y);
    SDL_RenderClear(screen->renderer);
    applyMenuStart(screen);
    if (x >= 393 && x <= 447 && y >= 325 && y <= 401){
        //Moins -}
        applyMoins(screen);
    }
    if (x >= 839 && x <= 892 && y >= 325 && y <= 401){
        //Plus +
        applyPlus(screen);
    }
    else if (x >= 503 && x <= 756 && y >= 486 && y <= 578){
        //Start
        applyStart(screen);
    }
    drawDifficulte(screen, world);
    SDL_RenderPresent(screen->renderer);
}
