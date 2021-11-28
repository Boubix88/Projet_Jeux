#include "map.h"
#include <math.h>

#define PLAYER_SIZE 4

float player_x = 1.5;
float player_y = 1.5;
float player_a = 1.523; //angle de vue

int playerHere(int x, int y) {
    if ((x >= player_x && y >= player_y) && (x <= player_x + PLAYER_SIZE && y <= player_y + PLAYER_SIZE)){
        printf("C'est vrai\n");
        return 1;
    }
    return 0;
}

void drawPlayer(unsigned char color[3]) {
    color[0] = 0;  //red 
    color[1] = 0;  //green
    color[2] = 0;  //blue
}

float laser() {
    float c;
    for (c = 0; c < 100; c+= 0.05) {
        float x = player_x + c*cosf(player_a);
        float y = player_y + c*sinf(player_a);
        printf("Valeur de x : %f\n", x);
        printf("Valeur de c : %f\n", c);
        if (drawMap((int) x,(int) y)){
            break;
        }
   }
    return c;
}