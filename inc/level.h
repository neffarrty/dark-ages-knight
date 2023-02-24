#pragma once

#include "header.h"

#define NUMBER_OF_LEVELS 4

#define MAX_NUMBER_OF_TILES_PER_LEVEL 50

typedef struct Obstacles {
	int solid[MAX_NUMBER_OF_TILES_PER_LEVEL];
	int death[MAX_NUMBER_OF_TILES_PER_LEVEL];
	int damage[MAX_NUMBER_OF_TILES_PER_LEVEL];
	int finish[MAX_NUMBER_OF_TILES_PER_LEVEL];
}	Obstacles;

typedef enum ObstaclesType {
	SOLID,
	DEATH,
	DAMAGE,
	END
}	ObstaclesType;

typedef enum LevelState {
	FINISH,
	RESTART,
	QUIT
}	LevelState;

typedef struct level {
	int number;
	int **map;
	const char *name;
	int startX;
	int startY;
	SDL_Texture* background;
	SDL_Texture* tiles;
	Obstacles obstacles;
	Mix_Music* music;
}	Level;

void renderLevel(Level* level, SDL_Renderer*);
Level *initLevels(SDL_Renderer*);

