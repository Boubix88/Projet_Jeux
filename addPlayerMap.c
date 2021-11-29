#include "map.h"
#include <math.h>

#define PLAYER_SIZE 4
#define M_PI 3.14159265358979323846
const float fov = M_PI/3.; // field of view

float player_x = 1.5;
float player_y = 1.5;
float player_a = 1.523; //angle de vue
const size_t rect_w = WIDTH/MAP_SIZE;
const size_t rect_h = HEIGHT/MAP_SIZE;

int playerHere(int x, int y) {
    //printf("Valeur de x : %d   Valeur de y : %d\n",x ,y);
    if ((x >= player_x*rect_w && y >= player_y*rect_h) && (x <= player_x*rect_w + PLAYER_SIZE && y <= player_y*rect_h + PLAYER_SIZE)){
        printf("Joueur affiché\n");
        return 1;
    }
    return 0;
}

void drawPlayer(unsigned char color[3]) {
    color[0] = 0;  //red 
    color[1] = 0;  //green
    color[2] = 0;  //blue
}



int fovHere(int x, int y, int i) {
    float t;
    float angle;

    angle = (player_a-fov)/2 + fov*i/(float)WIDTH;
    printf("Angle : %f\n", angle);
    for (t=0; t<20; t+=.05) {
        float cx = player_x + t*cos(angle);
        float cy = player_y + t*sin(angle);

        if (drawMap((int)cx, (int)cy)){
            //printf("Valeur de cx : %d   Valeur de cy : %d\n", cx, cy);
            break;
        }

        int pix_x = cx*rect_w;
        int pix_y = cy*rect_w;

        if (x == pix_x && y == pix_y){
            //printf("Valeur de t : %d   Boucle : %d\n", t, i);
            return 1;
        }
    }
    return 0;
}

void drawFov(unsigned char color[3]) {
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
}