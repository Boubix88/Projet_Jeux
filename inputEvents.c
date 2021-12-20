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
                    avancerDirection(world);
                    deplacementDroite(world);

                }
                //si la touche appuyée est 'Q'
                if (event->key.keysym.sym == SDLK_q || event->key.keysym.sym ==SDLK_LEFT){
                    printf("La touche Q est appuyee\n");
                    avancerDirection(world);
                    deplacementGauche(world);
                }
                //si la touche appuyée est 'Haut' ou 'Z'
                if (event->key.keysym.sym == SDLK_z || event->key.keysym.sym ==SDLK_UP){
                 avancerDirection(world);
                 deplacementAvant(world);
                }
                //si la touche appuyée est 'Bas' ou 'S'
                if (event->key.keysym.sym == SDLK_s || event->key.keysym.sym ==SDLK_DOWN){
                    printf("La touche S est appuyee\n");
                    avancerDirection(world);
                    deplacementArriere(world);
                }
                //si la touche appuyée est 'Echap'
                //si la touche appuyée est 'Echap'
                if (event->key.keysym.sym == SDLK_ESCAPE){
                    apply_menu(screen);
                    
                    SDL_WarpMouseInWindow(screen->window, 50, 720/2);
                    testSourisPosition(event, screen, world);
                }
            break;

            case SDL_MOUSEMOTION :
                if (event->motion.xrel > 0){
                    world->player_a += .005;
                }
                else{
                    world->player_a -= .005;
                }
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





void deplacementAvant(world_t* world) {
    float ancienx= world->player_x;
    float ancieny = world->player_y;
    if (world->vx > world->player_x && world->vy < world->player_y) {
        world->player_x =world->player_x + MOVING_STEP;
        world->player_y =world->player_y - MOVING_STEP;
        printf("Valeur de px: %f:\n", world->player_x);
        printf("Valeur de py: %f:\n", world->player_y);
        printf("Valeur de vx: %f:\n", world->vx);
        printf("Valeur de vy: %f:\n", world->vy);
    }
    else if (world->vx < world->player_x && world->vy < world->player_y) {
        world->player_x = world->player_x - MOVING_STEP;
        world->player_y = world->player_y - MOVING_STEP;
    }
    else if (world->vx == world->player_x && world->vy < world->player_y) {
        world->player_y = world->player_y - MOVING_STEP;

    }
    //gauche et droite
    else if (world->vx < world->player_x && world->vy == world->player_y) {
        world->player_x = world->player_x - MOVING_STEP;

    }
    else if (world->vx > world->player_x && world->vy == world->player_y) {
        world->player_x = world->player_x + MOVING_STEP;

    }

    //en bas.
    if (world->vx < world->player_x && world->vy > world->player_y) {
        world->player_y = world->player_y + MOVING_STEP;
        world->player_x = world->player_x - MOVING_STEP;
    }
    else if ((world->vx > world->player_x && world->vy > world->player_y)) {
        world->player_x = world->player_x + MOVING_STEP;
        world->player_y = world->player_y + MOVING_STEP;
    }
    else if (world->vx == world->player_x && world->vy > world->player_y) {
        world->player_y = world->player_y + MOVING_STEP;

    }


}
void deplacementArriere(world_t* world) {
    // on regarde en haut
    if (world->vx > world->player_x && world->vy < world->player_y) {
        world->player_x = world->player_x - MOVING_STEP;
        world->player_y = world->player_y + MOVING_STEP;
    }
    else if (world->vx < world->player_x && world->vy < world->player_y) {
        world->player_x = world->player_x + MOVING_STEP;
        world->player_y = world->player_y + MOVING_STEP;
    }
    else if (world->vx == world->player_x && world->vy < world->player_y) {
        world->player_y = world->player_y + MOVING_STEP;

    }
    //gauche et droite
    else if (world->vx < world->player_x && world->vy == world->player_y) {
        world->player_x = world->player_x + MOVING_STEP;

    }
    else if (world->vx > world->player_x && world->vy == world->player_y) {
        world->player_x = world->player_x - MOVING_STEP;

    }

    //en bas
    if (world->vx < world->player_x && world->vy > world->player_y) {
        world->player_x = world->player_x + MOVING_STEP;
        world->player_y = world->player_y - MOVING_STEP;
    }
    else if ((world->vx > world->player_x && world->vy > world->player_y)) {
        world->player_x = world->player_x - MOVING_STEP;
        world->player_y = world->player_y - MOVING_STEP;
    }
    else if (world->vx == world->player_x && world->vy > world->player_y) {
        world->player_y = world->player_y - MOVING_STEP;

    }


}
void deplacementGauche(world_t* world) {
    // en haut
    if (world->vx > world->player_x && world->vy < world->player_y) {
        world->player_x = world->player_x - MOVING_STEP;
        world->player_y = world->player_y - MOVING_STEP;
    }
    else if (world->vx < world->player_x && world->vy < world->player_y){
        world->player_x = world->player_x - MOVING_STEP;
        world->player_y = world->player_y + MOVING_STEP;
    }
    else if (world->vx == world->player_x && world->vy < world->player_y) {
        world->player_x = world->player_x - MOVING_STEP;

    }
    //gauche et droite
    else if (world->vx < world->player_x && world->vy == world->player_y) {
        world->player_y = world->player_y + MOVING_STEP;

    }
    else if (world->vx > world->player_x && world->vy == world->player_y) {
        world->player_y = world->player_y - MOVING_STEP;

    }

    //en bas
    if (world->vx < world->player_x && world->vy > world->player_y) {
        world->player_x = world->player_x + MOVING_STEP;
        world->player_y = world->player_y + MOVING_STEP;
    }
    else if((world->vx > world->player_x && world->vy > world->player_y)) {
        world->player_x = world->player_x + MOVING_STEP;
        world->player_y = world->player_y - MOVING_STEP;
    }
    else if (world->vx == world->player_x && world->vy > world->player_y) {
        world->player_x = world->player_x + MOVING_STEP;

    }


}


void deplacementDroite(world_t* world) {
    // en haut
    if (world->vx > world->player_x && world->vy < world->player_y) {
        world->player_x = world->player_x + MOVING_STEP;
        world->player_y = world->player_y + MOVING_STEP;
        
    }
    else if (world->vx < world->player_x && world->vy < world->player_y) {
        world->player_x = world->player_x + MOVING_STEP;
        world->player_y = world->player_y - MOVING_STEP;
    }
    else if (world->vx == world->player_x && world->vy < world->player_y) {
        world->player_x = world->player_x + MOVING_STEP;

    }
    //gauche et droite
    else if (world->vx < world->player_x && world->vy == world->player_y) {
        world->player_y = world->player_y - MOVING_STEP;

    }
    else if (world->vx > world->player_x && world->vy == world->player_y) {
        world->player_y = world->player_y + MOVING_STEP;

    }

    //en bas
    if (world->vx < world->player_x && world->vy > world->player_y) {
        world->player_x = world->player_x - MOVING_STEP;
        world->player_y = world->player_y - MOVING_STEP;
    }
    else if ((world->vx > world->player_x && world->vy > world->player_y)) {
        world->player_x = world->player_x - MOVING_STEP;
        world->player_y = world->player_y + MOVING_STEP;
    }
    else if (world->vx == world->player_x && world->vy > world->player_y) {
        world->player_x = world->player_x - MOVING_STEP;

    }


}

bool testMur(world_t* world) {
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
    if ( map[(int)world->player_x][(int)world->player_y]== '1') {
        return true;

    }
    return false;
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