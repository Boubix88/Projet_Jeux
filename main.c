#include "main.h"

int main(int argc, char *argv[]){
    screen_t screen;
    SDL_Init(SDL_INIT_VIDEO);
    Init_Screen(&screen);
    SDL_Delay(3000);
    SDL_Quit();
    SDL_DestroyWindow(screen.window);
    return EXIT_SUCCESS;
}