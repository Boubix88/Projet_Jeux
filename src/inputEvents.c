#include "main.h"


void handle_events(SDL_Event *event, world_t *world, screen_t *screen){
    
    while(SDL_PollEvent(event)){
        switch(event->type) {
            //si une touche est appuyée
            case SDL_QUIT :
                world->exit = true;
            break;

            case SDL_KEYDOWN :
                printf("Touche appuyee\n");
                //si la touche appuyée est 'D' 
                if(event->key.keysym.sym == SDLK_d || event->key.keysym.sym == SDLK_RIGHT){
                    printf("La touche D est appuyee\n");
                    world->angle += M_PI / 2;
                    avancerDirection(world);
                    world->player_x += world->vx * MOVING_STEP;
                    world->player_y += world->vy * MOVING_STEP;
                    world->angle -= M_PI / 2;
                    avancerDirection(world);
                }
                //si la touche appuyée est 'Q'
                if (event->key.keysym.sym == SDLK_q || event->key.keysym.sym ==SDLK_LEFT){
                    printf("La touche Q est appuyee\n");
                    world->angle += M_PI / 2;
                    avancerDirection(world);
                    world->player_x -= world->vx * MOVING_STEP;
                    world->player_y -= world->vy * MOVING_STEP;
                    world->angle -= M_PI / 2;
                    avancerDirection(world);
                }
                //si la touche appuyée est 'Haut' ou 'Z'
                if (event->key.keysym.sym == SDLK_z || event->key.keysym.sym ==SDLK_UP){
                    printf("La touche Z est appuyee\n");
                    world->player_x += world->vx * MOVING_STEP;
                    world->player_y += world->vy * MOVING_STEP;
                }
                //si la touche appuyée est 'Bas' ou 'S'
                if (event->key.keysym.sym == SDLK_s || event->key.keysym.sym ==SDLK_DOWN){
                    printf("La touche S est appuyee\n");
                    world->player_x -= world->vx * MOVING_STEP;
                    world->player_y -= world->vy * MOVING_STEP;
                }
                //si la touche appuyée est 'Echap'
                if (event->key.keysym.sym == SDLK_ESCAPE){
                    initialiserTexturesMenu(screen);
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
                            SDL_RenderPresent(screen->renderer);
                        }else if(world->fpsView){
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
                SDL_ShowCursor(SDL_DISABLE);

                if (event->motion.xrel > 0){
                    world->player_a += .005;
                }
                else{
                    world->player_a -= .005;
                }
                world->angle = world->player_a;
                avancerDirection(world);
            break;
        }
    }
}

void testSourisPosition(SDL_Event* event, screen_t* screen,world_t* world){
    bool continuer = false;
    int x, y;
    while (!continuer){
        //Applique les couleurs des options selon la position de la souris
        applyMenuOption(screen);
        while(SDL_PollEvent(event)){
            switch(event->type) {
                case SDL_MOUSEBUTTONDOWN :
                    SDL_GetMouseState(&x, &y);
                    if (x >= 461 && x <= 808 && y >= 152 && y <= 201){
                        //Continuer, on continue
                        continuer = true;
                    }
                    else if (x >= 428 && x <= 854 && y >= 305 && y <= 366){
                        //Graphismes, pour l'instant on continue
                        continuer = true;
                    }
                    else if (x >= 524 && x <= 759 && y >= 464 && y <= 521){
                        //Quitter
                        world->exit = true;
                        continuer = true;    
                    }
                break;
            }
        }

    }
}