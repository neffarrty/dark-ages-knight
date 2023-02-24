#include "../inc/header.h"

void doPlayer(void) {
    player->dx = 0;

    moveType = STAY;
    Mix_Chunk* run = Mix_LoadWAV("resource/music/run.wav");
    if (keyboard[SDL_SCANCODE_LEFT]) {
        player->dx = -PLAYER_SPEED;
        moveType = MOVE_LEFT;
        Mix_PlayChannel(-1, run, 0);
    }

    if (keyboard[SDL_SCANCODE_RIGHT]) {
        player->dx = PLAYER_SPEED;
        moveType = MOVE_RIGHT;
        Mix_PlayChannel(-1, run, 0);
    }

    if (keyboard[SDL_SCANCODE_SPACE] && player->isOnGround) {
        player->dy = -21.5;
        player->isOnGround = false;
    }
    Mix_FreeChunk(run);
}


