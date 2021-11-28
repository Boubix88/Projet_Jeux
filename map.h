#ifndef map_H
#define map_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constante.h"

int drawMap(int x, int y);
void drawPlayer(unsigned char color[3]);
int playerHere(int x, int y);
void drawFov(unsigned char color[3]);
int fovHere(int x, int y, int i);

#define MAP_SIZE 16

typedef struct{
    int map [MAP_SIZE][MAP_SIZE];


}Map;


#endif