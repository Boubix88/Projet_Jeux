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
                    world->player_x -= MOVING_STEP;
                }
                //si la touche appuyée est 'Q'
                if (event->key.keysym.sym == SDLK_q || event->key.keysym.sym ==SDLK_LEFT){
                    printf("La touche Q est appuyee\n");
                    world->player_x += MOVING_STEP;
                }
                //si la touche appuyée est 'Haut' ou 'Z'
                if (event->key.keysym.sym == SDLK_z || event->key.keysym.sym ==SDLK_UP){
                 printf("La touche Z est appuyee\n");
                    world->player_y += MOVING_STEP;
                }
                //si la touche appuyée est 'Bas' ou 'S'
                if (event->key.keysym.sym == SDLK_s || event->key.keysym.sym ==SDLK_DOWN){
                    printf("La touche S est appuyee\n");
                    world->player_y -= MOVING_STEP;
                }
                //si la touche appuyée est 'Echap'
                if (event->key.keysym.sym == SDLK_ESCAPE){
                    printf("La touche ECHAP est appuyee\n");
                    world->exit = true;
                }
            break;

            case SDL_MOUSEMOTION :
                //printf("La souris bouge, x : %d\n", event->motion.x);
                world->player_a = (float)event->motion.x/1000;
                //printf("Player_a : %f", world->player_a); 
            break;
        }
    }
}