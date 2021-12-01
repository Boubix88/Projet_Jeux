#include "map.h"

int main(void) {
  FILE *file= fopen("map.ppm", "wb"); // mode binaire
  (void) fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  unsigned char *img = malloc(WIDTH*HEIGHT*3);

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
  initialisationMap(img);
  drawWalls(map, img);
  drawFov(map, img);
  drawMap(img, file);
  
  (void) fclose(file);
  return EXIT_SUCCESS;
}

void initialisationMap(unsigned char *img){
   for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
        int idx = (i+j*WIDTH)*3;
        for (int c=0; c<3; c++){
          img[idx+c] = 255;
        }
    }
  }
}

void drawWalls(const char map[16][16], unsigned char *img){
    for (int i=0; i<16; i++)
    for (int j=0; j<16; j++)
      if (map[i][j]=='1') {
          int x = i*WIDTH/16;
          int y = j*HEIGHT/16;
        for (int a=0; a<WIDTH/16; a++)
          for (int b=0; b<HEIGHT/16; b++) {
          img[(x+a+(y+b)*WIDTH)*3] = 0;
          }
      }
}

void drawFov(const char map[16][16], unsigned char *img){
  float player_x = 2;
    float player_y = 7.5;
    float player_a = 0.1789;
    float player_fov = 1.58;

    for (int r=0; r<512; r++) { 
      float angle = player_a - player_fov/2 + player_fov*r/512;      
    
    for (float t=0; t<20; t+=.001) {
        float cx = player_x + t*cos(angle);
        float cy = player_y + t*sin(angle);

        if (map[(int)(cx)][(int)(cy)]!=' ') break;

        int pixx = cx * WIDTH/16;
        int pixy = cy * HEIGHT/16;

        for (int c=0; c<3; c++) {
          img[(pixx + pixy*WIDTH)*3+c] = 0;
        }
    }
    }
}

void drawMap(unsigned char *img, FILE *file){
  for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
        int idx = (i+j*WIDTH)*3;
        fwrite(img+idx, 1, 3, file);
    }
  }
}

/*color[0] = 255;  //red 
color[1] = (i + j)/8;  //green     // Pour le degrade
color[2] = (i + j)/4;  //blue*/