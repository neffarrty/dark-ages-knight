#include "../inc/header.h"

void drawMap(SDL_Renderer* renderer, SDL_Texture* texture, int **map, int tile_width, int tile_height) {
    for (int row = 0; row < MAP_HEIGHT; row++) {
        for (int col = 0; col < MAP_WIDTH; col++) {
            int tile_id = map[row][col];

            SDL_Rect src_rect = {
                (tile_id % NUM_TILES_PER_ROW) * tile_width,
                (tile_id / NUM_TILES_PER_ROW) * tile_height,
                tile_width,
                tile_height
            };

            SDL_Rect dest_rect = {
                col * DISPLAY_TILE_SIZE,
                row * DISPLAY_TILE_SIZE,
                DISPLAY_TILE_SIZE,
                DISPLAY_TILE_SIZE
            };

            SDL_RenderCopy(renderer, texture, &src_rect, &dest_rect);
        }
    }
}

