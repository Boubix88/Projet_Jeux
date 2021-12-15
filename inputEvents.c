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
                 avancerDirection(world);
                 deplacement(world);
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


void avancerDirection(world_t* world) {
    const char map[16][16] = { "1111111111111111",
                              "1   11   11   11",
                              "1   11   11   11",
                              "11 1111 1111 111",
                              "1              1",
                              "11111111111111 1",
                              "1  1         1 1",
                              "1  1   1 11  1 1",
                              "1    1       1 1",
                              "111  1 1  1  1 1",
                              "1      1 1   1 1",
                              "1  1 1 1       1",
                              "1  1       1   1",
                              "1    1  1 1  1 1",
                              "1     1      1 1",
                              "1111111111111111" };
    float player_x = 5;
    float player_y = 6;
    float player_a = world->player_a;
    float player_fov = 1.58;
    int r = 256;
    float angle = player_a - player_fov / 2 + player_fov * r / 512;
    for (float t = 0; t < 20; t += .001) {
        float cx = player_x + t * cos(angle);
        float cy = player_y + t * sin(angle);
        int ax = cx;
        int ay = cy;
        if (map[ay][ax] != ' ') {
            world->vx = cx;
            world->vy = cy;
            world->dis = t;
        }
    }
}





void deplacement(world_t* world) {
     if (world->player_x > world->vx) {
        world->player_x = world->player_x + MOVING_STEP;
    }
    else {
        world->player_x = world->player_x - MOVING_STEP;
    }
    if (world->player_y > world->vy) {
        world->player_y = world->player_y - MOVING_STEP;
    }
    else {
        world->player_y = world->player_y + MOVING_STEP;
    }


}