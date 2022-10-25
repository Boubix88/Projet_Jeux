#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "graphics.h"
#include <stdbool.h>
#include <SDL_ttf.h>
#include "constante.h"
#include <time.h>

typedef struct sprite_s
{
    float x, y;
    float xMap, yMap;
    float direction;
    short h;
    short w;

}sprite_t;

typedef struct world_s
{
    float player_a;
    float angle;
    float player_x;
    float player_y;
    float ancienPlayer_x;
    float ancienPlayer_y;
    bool exit; 
    float vx;       //coordonnee du point x pour se deplacer
    float vy;       //coordonnee du point y pour se deplacer
    float dis;
    short map[MAP_SIZE][MAP_SIZE];
    bool fpsView;
    bool ammoShooted;
    bool graphisme;
    bool objectif;
    int compteurNbreImpact;
    short difficulte;
    bool continuer;

    float graphismeOption;
    short graphismeOptionRayon;
    short graphismeOptionWidth;
    int  paquetrayon;
    short fps_lasttime;
    short fps_current; 
    short fps_frames;
    int score;
    bool tonyMort;
    sprite_t monstre[MAX_SPRITE];
    sprite_t ammo;

}world_t;




void handle_events(SDL_Event *event, world_t *world, screen_t *screen);

void draw3DMapSdl(screen_t* screen, world_t *world);
void map(screen_t* screen, world_t *world);
void drawSky(screen_t* screen);
void drawGround(screen_t* screen);
void calculFPS(world_t* world);
void drawFPS(world_t* world, screen_t* screen);
void initialiserTexture(screen_t* screen);

void drawMiniMap(screen_t* screen, world_t* world);
void drawWalls(screen_t *screen, world_t* world);
void drawPlayer(screen_t* screen, world_t* world);
void drawFov(screen_t* screen, world_t* world);
void deplacementAvant(world_t*world);
void deplacementArriere(world_t* world);
void deplacementGauche(world_t* world);
void deplacementDroite(world_t* world);
void avancerDirection(world_t* world);
bool testMur(world_t* world);
void applyMenuOption(screen_t* screen);
void testSourisPosition(SDL_Event* event, screen_t* screen,world_t* world);
void apply_menu(screen_t* screen);
void testCollision(world_t* world);
void applyCrosshair(screen_t* screen);
void initialiserTexturesMenu(screen_t* screen);
void destroyTexturesMenu(screen_t* screen);
void intitialiserData(world_t* world);
void initialiserDeplacement(world_t* world);
void createMap(world_t* world);
void applyPistolet(screen_t* screen);
void applyTirPistolet(screen_t* screen);
void applyViseeFpsPistolet(screen_t* screen);
void applyTirPistoletFps(screen_t* screen);
void setMonstre(world_t* world);
void drawMonstre(screen_t* screen,world_t* world);
void drawMonstre3D(world_t* world, screen_t* screen,int k,float t, short r);
void drawAmmo(screen_t* screen, world_t* world);
void initialiserTexturesMenuGraphisme(screen_t* screen);
void applyMenuGraphisme(screen_t* screen);
void applyMenuGraphismeOption(screen_t* screen);
void destroyTextures(screen_t* screen);
void drawExplosion(screen_t* screen, world_t* world);
void initialiserTextureMenuStart(screen_t* screen);
void applyMenuStart(screen_t* screen);
void applyStart(screen_t* screen);
void applyMoins(screen_t* screen);
void applyPlus(screen_t* screen);
void destroyTexturesMenuStart(screen_t* screen);
void testSourisMenuStart(SDL_Event* event, screen_t* screen,world_t* world);
void drawDifficulte(screen_t* screen, world_t* world);
void testPositionSourisMenuStart(screen_t* screen, world_t* world);
void ancienCoord(world_t* world);
void ecrireScore(world_t* world);
SDL_Surface *load_bmp(char const *path, SDL_Surface *windowSurface);