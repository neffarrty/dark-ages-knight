#include "../inc/header.h"
#include "../inc/level.h"

bool checkTileCollisions(SDL_Rect* pos, int **tilemap, int obstacleType, Obstacles obstacles) {
    int xStart = pos->x / DISPLAY_TILE_SIZE;
    int xEnd = ceil((double) (pos->x + pos->w) / DISPLAY_TILE_SIZE);
    int yStart = pos->y / DISPLAY_TILE_SIZE;
    int yEnd = ceil((double) (pos->y + pos->h) / DISPLAY_TILE_SIZE);

    for(int y = yStart; y < yEnd; y++){
        for(int x = xStart; x < xEnd; x++){
            bool isOutside = x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT;
            int here = isOutside ? obstacles.solid[0] : tilemap[y][x];

            if(obstacleType == SOLID) {
                for(int i = 0; obstacles.solid[i] != -1; i++) {
                    if(here == obstacles.solid[i]) {
                        return true;
                    }
                }
            }

            if(obstacleType == DEATH) {
                for(int i = 0; obstacles.death[i] != -1; i++) {
                    if(here == obstacles.death[i]) {
                        return true;
                    }
                }
            }

            if(obstacleType == DAMAGE) {
                for(int i = 0; obstacles.damage[i] != -1; i++) {
                    if(here == obstacles.damage[i]) {
                        return true;
                    }
                }
            }

            if(obstacleType == END) {
                for(int i = 0; obstacles.finish[i] != -1; i++) {
                    if(here == obstacles.finish[i]) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}


