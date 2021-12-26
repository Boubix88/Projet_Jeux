#include "main.h"

void avancerDirection(world_t* world) {
    if(world->angle < 0) {
        world->angle += 2 * M_PI;
    } else if(world->angle > 2 * M_PI) {
        world->angle -= 2 * M_PI;
    }
    world->vx = cos(world->angle);
    world->vy = sin(world->angle);
}

void initialiserDeplacement(world_t* world){
    world->angle = world->player_a;
    world->vx = cos(world->player_a);
    world->vy = sin(world->player_a);
}