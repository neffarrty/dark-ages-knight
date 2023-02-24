#include "../inc/header.h"

Level *initLevels(SDL_Renderer* renderer) {
    Obstacles levelObstacles[NUMBER_OF_LEVELS];

	// ----------- Level 0 Obtacles ------------------------

	levelObstacles[0].solid[0] = 0;
	levelObstacles[0].solid[1] = 1;
	levelObstacles[0].solid[2] = 2;
	levelObstacles[0].solid[3] = 9;
	levelObstacles[0].solid[4] = 14;
	levelObstacles[0].solid[5] = 15;
	levelObstacles[0].solid[6] = 16;
	levelObstacles[0].solid[7] = 17;
	levelObstacles[0].solid[8] = 20;
	levelObstacles[0].solid[9] = 21;
	levelObstacles[0].solid[10] = 22;
	levelObstacles[0].solid[11] = 23;
	levelObstacles[0].solid[12] = -1;

	levelObstacles[0].death[0] = -1;

	levelObstacles[0].damage[0] = 8;
	levelObstacles[0].damage[1] = -1;

	levelObstacles[0].finish[0] = 4;
	levelObstacles[0].finish[1] = -1;

	// ------------ [END] Level 0 Obstacles -----------------

	// ----------- Level 1 Obtacles ------------------------

	levelObstacles[1].solid[0] = 0;
	levelObstacles[1].solid[1] = 1;
	levelObstacles[1].solid[2] = 2;
	levelObstacles[1].solid[3] = 9;
	levelObstacles[1].solid[4] = 14;
	levelObstacles[1].solid[5] = 15;
	levelObstacles[1].solid[6] = 16;
	levelObstacles[1].solid[7] = 17;
	levelObstacles[1].solid[8] = 20;
	levelObstacles[1].solid[9] = 21;
	levelObstacles[1].solid[10] = 22;
	levelObstacles[1].solid[11] = 23;
	levelObstacles[1].solid[12] = -1;

	levelObstacles[1].death[0] = -1;

	levelObstacles[1].damage[0] = 8;
	levelObstacles[1].damage[1] = -1;

	levelObstacles[1].finish[0] = 4;
	levelObstacles[1].finish[1] = -1;

	// ------------ [END] Level 1 Obstacles -----------------

	// ----------- Level 2 Obtacles ------------------------

	levelObstacles[2].solid[0] = 0;
	levelObstacles[2].solid[1] = 1;
	levelObstacles[2].solid[2] = 2;
	levelObstacles[2].solid[3] = 3;
	levelObstacles[2].solid[4] = 4;
	levelObstacles[2].solid[5] = 5;
	levelObstacles[2].solid[6] = 6;
	levelObstacles[2].solid[7] = 7;
	levelObstacles[2].solid[8] = 8;
	levelObstacles[2].solid[9] = 9;
	levelObstacles[2].solid[10] = 10;
	levelObstacles[2].solid[11] = 11;
	levelObstacles[2].solid[12] = 13;
	levelObstacles[2].solid[13] = 14;
	levelObstacles[2].solid[14] = 15;
	levelObstacles[2].solid[15] = 16;
	levelObstacles[2].solid[16] = 17;
	levelObstacles[2].solid[17] = 18;
	levelObstacles[2].solid[18] = 21;
	levelObstacles[2].solid[19] = -1;

	levelObstacles[2].death[0] = -1;

	levelObstacles[2].damage[0] = 12;
	levelObstacles[2].damage[1] = 20;
	levelObstacles[2].damage[2] = 22;
	levelObstacles[2].damage[3] = -1;

	levelObstacles[2].finish[0] = 19;
	levelObstacles[2].finish[1] = -1;

	// ------------ [END] Level 2 Obstacles -----------------

	// ----------- Level 3 Obtacles ------------------------

	levelObstacles[3].solid[0] = 0;
    levelObstacles[3].solid[1] = 1;
    levelObstacles[3].solid[2] = 3;
    levelObstacles[3].solid[3] = 8;
    levelObstacles[3].solid[4] = 15;
    levelObstacles[3].solid[5] = 16;
    levelObstacles[3].solid[6] = 21;
    levelObstacles[3].solid[7] = 18;
    levelObstacles[3].solid[8] = 23;
    levelObstacles[3].solid[9] = 12;
	levelObstacles[3].solid[19] = -1;

	levelObstacles[3].death[0] = 20;
	levelObstacles[3].death[1] = -1;

	levelObstacles[3].damage[0] = 21;
	levelObstacles[3].damage[1] = -1;

	levelObstacles[3].finish[0] = 19;
	levelObstacles[3].finish[1] = -1;

	// ------------ [END] Level 3 Obstacles -----------------

    const char *LEVELS_PATH_FILES[NUMBER_OF_LEVELS] = {
      "resource/levels/level0.txt",
      "resource/levels/level1.txt",
      "resource/levels/level2.txt",
	  "resource/levels/level3.txt",
    };

    const char *LEVELS_BACKG_FILES[NUMBER_OF_LEVELS] = {
      "resource/img/level_backgrounds/back0.png",
      "resource/img/level_backgrounds/back1.png",
      "resource/img/level_backgrounds/back2.png",
	  "resource/img/level_backgrounds/back3.png",
    };

    const char *LEVELS_NAMES[NUMBER_OF_LEVELS] = {
	  "The Journey's Start",
      "Throughout the Forbiden Forest",
	  "In the Hall of the Mountain King",
      "Under The Malakar's Castle",
    };

    const char *LEVELS_TILES[NUMBER_OF_LEVELS] = {
      "resource/img/tiles/tile0.png",
	  "resource/img/tiles/tile0.png",
      "resource/img/tiles/tile2.png",
      "resource/img/tiles/tile3.png",
    };

	const char *LEVELS_MUSIC[NUMBER_OF_LEVELS] = {
      "resource/music/levels/level0.mp3",
	  "resource/music/levels/level1.mp3",
      "resource/music/levels/level2.mp3",
      "resource/music/levels/level3.mp3",
    };

    Level *levels = (Level*)malloc(NUMBER_OF_LEVELS * sizeof(Level));
    memset(levels, 0, sizeof(Level) * NUMBER_OF_LEVELS);

    for(int i = 0; i < NUMBER_OF_LEVELS; i++) {
      	levels[i].number = i + 1;
      	levels[i].map = translateMap(LEVELS_PATH_FILES[i]);
      	levels[i].name = LEVELS_NAMES[i];
      	levels[i].background = loadTextureFromImage(renderer, LEVELS_BACKG_FILES[i]);
      	levels[i].tiles = loadTextureFromImage(renderer, LEVELS_TILES[i]);
        levels[i].obstacles = levelObstacles[i];
		levels[i].music = Mix_LoadMUS(LEVELS_MUSIC[i]);
    }

	levels[0].startX = 100;
	levels[0].startY = SCREEN_HEIGHT - 200;

	levels[1].startX = 100;
	levels[1].startY = SCREEN_HEIGHT - 200;

	levels[2].startX = 100;
	levels[2].startY = SCREEN_HEIGHT - 200;

	levels[3].startX = 100;
	levels[3].startY = SCREEN_HEIGHT - 200;

    return levels;
}

