#include "map.h"

int main(void) {
  FILE *file= fopen("map.ppm", "wb"); // mode binaire
  (void) fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  unsigned char color[3];

  for (int j = 0; j < HEIGHT; j++)
  {
    for (int i = 0; i < WIDTH; i++)
    {
      if (playerHere(i, j)){
        drawPlayer(color);
      }else if (drawMap(i/32, j/32)){ // On appel la fonction toute les 32 lignes
        color[0] = 1;  //red 
        color[1] = 200;  //green
        color[2] = 255;  //blue
      }
      else if (fovHere(i, j, i)){
        drawFov(color);
      }else {
        color[0] = 255;  //red 
        color[1] = (i + j)/8;  //green
        color[2] = (i + j)/4;  //blue
      }
      (void) fwrite(color, 1, 3, file);
    }
  }
  (void) fclose(file);
  return EXIT_SUCCESS;
}

int drawMap(int x, int y) {
  const char map[16][16] = {"1111111111111111",
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
                            "1111111111111111"}; 

  if(map[y][x] == '1'){ // si on tombe sur un 1, return 1
    return 1;
  }
  return 0;
}