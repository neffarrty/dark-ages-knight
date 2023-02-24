#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "stringFuncs.h"
#include "level.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define PLAYER_SPEED 4
#define FPS 60
#define MENU_ITEM_COUNT 2

#define TILE_SIZE 16
#define DISPLAY_TILE_SIZE 32
#define MAP_WIDTH 60
#define MAP_HEIGHT 34
#define NUM_TILES_PER_ROW 5

#define GRAVITY 1.5

#define MAX_KEYBOARD_KEYS 350

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct{
	float dx;
	float dy;
	bool isOnGround;
	SDL_Texture* texture;
    SDL_Rect spriteRect;
    SDL_Rect spritePosition;
} Entity;

extern Entity *player;

extern int keyboard[MAX_KEYBOARD_KEYS];

bool initSDL(void);
void clearSDL(SDL_Renderer* renderer, SDL_Window* window);

int showMenu(SDL_Renderer* renderer, TTF_Font* font);
void renderMenu(SDL_Renderer* renderer, TTF_Font* font, int selectedItem, const char** MENU_ITEMS);

SDL_Texture* loadTextureFromImage(SDL_Renderer* renderer, const char *filePath);

void renderHP(SDL_Renderer* renderer, int playerHP);
void renderLevelBar(SDL_Renderer* renderer, TTF_Font* font, int currentLevel, const char* levelName);

char* intToString(int i);

void drawMap(SDL_Renderer* renderer, SDL_Texture* texture, int **map, int tile_width, int tile_height);
int **translateMap(const char *filename);
bool checkTileCollisions(SDL_Rect* pos, int **tilemap, int obstacleType, Obstacles obstacles);

void doKeyUp(SDL_KeyboardEvent *event);
void doKeyDown(SDL_KeyboardEvent *event);
void doPlayer(void);
int startLevel(Level *level, SDL_Renderer* renderer, int playerStartX, int playerStartY, TTF_Font* font, int playerHP);

typedef enum moveType {
    MOVE_LEFT,
    MOVE_RIGHT,
    STAY,
}   MoveType;

extern MoveType moveType;

void loadPlayerMoveTexture(SDL_Renderer* renderer, Entity* player, MoveType moveType, int *frameWidth);


