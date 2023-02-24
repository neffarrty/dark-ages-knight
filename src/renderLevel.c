#include "../inc/header.h"

void renderLevel(Level* level, SDL_Renderer* renderer) {
    SDL_Rect backgRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, level->background, NULL, &backgRect);

    drawMap(renderer, level->tiles, level->map, TILE_SIZE, TILE_SIZE);
}

