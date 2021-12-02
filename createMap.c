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
  //initilaisationMap3D(img);
  drawWalls(map, img);
  drawPlayer(img);
  drawFov(map, img);
  draw3DMap(map, img);
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

/*void initilaisationMap3D(unsigned char *img){
  for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
        int idx = (i+j*WIDTH)*3;
        for (int c=0; c<3; c++){
          img[idx+c] = 255;
        }
    }
  }
}*/

void drawWalls(const char map[16][16], unsigned char *img){
    for (int i=0; i<16; i++)
    for (int j=0; j<16; j++)
      if (map[j][i]=='1') {
          int x = i*(WIDTH/2)/16;
          int y = j*HEIGHT/16;
        for (int a=0; a<(WIDTH/2)/16; a++)
          for (int b=0; b<HEIGHT/16; b++) {
          img[(x+a+(y+b)*(WIDTH))*3] = 0;
          }
      }
}

void drawPlayer(unsigned char *img){
  float player_x = 5*32;
  float player_y = 6*32;
  for (int i = 0; i < PLAYER_SIZE; i++){
    for (int j = 0; j < PLAYER_SIZE; j++){
      int idx = (player_x+i+(player_y+j)*(WIDTH))*3;
      for (int c=0; c<3; c++){
        img[idx+c] = 127;
      }
    }
  }
}

void drawFov(const char map[16][16], unsigned char *img){
  float player_x = 5;
    float player_y = 6;
    float player_a = 1.8;
    float player_fov = 1.58;

    for (int r=0; r<512; r++) { 
      float angle = player_a - player_fov/2 + player_fov*r/512;      
    
    for (float t=0; t<20; t+=.001) {
        float cx = player_x + t*cos(angle);
        float cy = player_y + t*sin(angle);

        if (map[(int)(cy)][(int)(cx)]!=' ') break;

        int pixx = cx * (WIDTH/2)/16;
        int pixy = cy * HEIGHT/16;

        for (int c=0; c<3; c++) {
          img[(pixx + pixy*(WIDTH))*3+c] = 0;
        }
    }
    }
}

void draw3DMap(const char map[16][16], unsigned char *img){
  float player_x = 5;
  float player_y = 6;
  float player_a = 1.8;
  float player_fov = 1.58;

  for (int r=0; r<512; r++) { 
      float angle = player_a - player_fov/2 + player_fov*r/512;      
    
    for (float t=0; t<20; t+=.001) {
        float cx = player_x + t*cos(angle);
        float cy = player_y + t*sin(angle);

        if (map[(int)(cy)][(int)(cx)]!=' '){
          int line_height = HEIGHT/t;
          /*for (int c=0; c<3; c++) {
            //img[(r*2+line_height*WIDTH)*3+c] = 160;
            img[(512+r+line_height*WIDTH)*3+c] = 160;
          }*/
          drawLine(img, WIDTH/2+r, HEIGHT*1.5-line_height/2, 1, line_height);
          break;
        }
    }
  }
}

void drawLine(unsigned char *img,float x, float y, float w, float h) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            float cx = x + i;
            float cy = y + j;
            img[(int)cx + (int)cy*WIDTH] = 160;
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