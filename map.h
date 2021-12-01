#ifndef map_H
#define map_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constante.h"
#include <SDL2/SDL.h>

void initialisationMap(unsigned char *img);
void drawWalls(const char map[16][16], unsigned char *img);
void drawFov(const char map[16][16], unsigned char *img);
void drawMap(unsigned char *img, FILE *file);

typedef struct{
    int map [MAP_SIZE][MAP_SIZE];
    int compteur;

}Map;

#endif