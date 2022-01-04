#include "main.h"
#include <fcntl.h>
#include <unistd.h>
void intitialiserData(world_t* world){
    createMap(world);
    setMonstre(world);

    world->player_a = 1.8;
    world->player_x = 2;
    world->player_y = 2;
    world->score = 0;
    world->exit = false;
    world->graphisme = false;
    world->graphismeOption = .002;
    world->graphismeOptionRayon = 512;
    world->graphismeOptionWidth = 1;
    world->tonyMort = false;
    world->fps_lasttime = SDL_GetTicks(); //Le dernier temps enregistré
    world->fps_frames = 0; //Le nombre d'images depuis le dernier FPS
    world->fps_current = 0; //Les FPS du moment

    world->ammo.x = 1280/2 + 70;
    world->ammo.y = 720/2 + 80;
    world->ammo.w = AMMO_WIDTH;
    world->ammo.h = AMMO_HEIGHT;

    world->ammoShooted = false;
    world->angleSky = world->player_a;
    world->compteurNbreImpact = 0;
}

void calculFPS(world_t* world){
    world->fps_frames++;
    if (world->fps_lasttime < SDL_GetTicks() - FPS_INTERVAL*1000){
        world->fps_lasttime = SDL_GetTicks();
        world->fps_current = world->fps_frames;
        world->fps_frames = 0;
    }
}

bool testMur(world_t* world) {
    if (world->map[(int)world->player_y][(int)world->player_x] != ' ') {
        return true;
    }
    return false;
}

void testCollision(world_t* world){
    if (testMur(world)){ 
        world->player_x = world->ancienPlayer_x;
        world->player_y = world->ancienPlayer_y;
    }
}

void setMonstre(world_t* world) {
    srand(time(NULL));

    for (short i = 0; i < DIFFICULTE; i++){
        //Initialisation des coordonnées à 0
        world->monstre[i].x = 0;
        world->monstre[i].y = 0;
        while (world->monstre[i].x == 0 || world->monstre[i].y == 0){
            //Initialisation des coordonnées avec un random
            short random_x = rand() % 14 + 1;
            short random_y = rand() % 14 + 1;
            if (world->map[random_y][random_x] == ' '){
                world->monstre[i].x = random_x ;
                world->monstre[i].y = random_y ;
            }
        }
    }
}


void ecrireScore(world_t* world) {
    FILE* f;
    f = fopen("score.txt", "w");
    fprintf(f,"%d", world->score);
    fclose(f);
}