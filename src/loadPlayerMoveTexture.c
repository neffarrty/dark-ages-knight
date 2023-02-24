#include "../inc/header.h"

void loadPlayerMoveTexture(SDL_Renderer* renderer, Entity* player, MoveType moveType, int *textureWidth) {
    int textureHeigth;

    int frameHeigth;
    int frameWidth;

    switch(moveType) {
        case MOVE_LEFT:
            player->texture = loadTextureFromImage(renderer, "resource/img/sprite/run_left.png");
            break;
        case MOVE_RIGHT:
            player->texture = loadTextureFromImage(renderer, "resource/img/sprite/run_right.png");
            break;
        case STAY:
            player->texture = loadTextureFromImage(renderer, "resource/img/sprite/run_right.png");
            break;
    }
     
    SDL_QueryTexture(player->texture, NULL, NULL, textureWidth, &textureHeigth);
    
    frameWidth = *textureWidth / 7;
    frameHeigth = textureHeigth;

    player->spriteRect.w = frameWidth;
    player->spriteRect.h = frameHeigth;
}

