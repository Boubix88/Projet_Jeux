#ifndef map_H
#define map_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constante.h"
#include <SDL2/SDL.h>

void initialisationMap(unsigned char *img);
void initilaisationMap3D(unsigned char *img);
void drawMap(unsigned char *img, FILE *file);
void draw3DMap(const char map[16][16], unsigned char *img);
void drawLine(unsigned char *img, float x, float y, float w, float h);

typedef struct{
    int map [MAP_SIZE][MAP_SIZE];
    int compteur;

}Map;

#endif