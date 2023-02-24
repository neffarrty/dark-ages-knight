#include "../inc/header.h"
    
Entity *player;
int keyboard[MAX_KEYBOARD_KEYS];
MoveType moveType = STAY;

static void clearLevel(Entity *player, SDL_Texture *spriteTexture) {
    free(player);
    SDL_DestroyTexture(spriteTexture);
}

int startLevel(Level *level, SDL_Renderer* renderer, int startX, int startY, TTF_Font* font, int playerHP) {
    int frameWidth, frameHeigth;
    int textureWidth, textureHeigth;
    int frameTime = 0;

    //------------ Working with sprite animation ---------------

    // Load sprite image
    player = (Entity*)malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));

    player->texture = loadTextureFromImage(renderer, "resource/img/sprite/run_right.png");
    
    SDL_QueryTexture(player->texture, NULL, NULL, &textureWidth, &textureHeigth);
    
    frameWidth = textureWidth / 7;
    frameHeigth = textureHeigth;

    player->spriteRect.x = 0;
    player->spriteRect.y = 0;
    player->spriteRect.w = frameWidth;
    player->spriteRect.h = frameHeigth;

    player->spritePosition.x = startX;
    player->spritePosition.y = startY;
    player->spritePosition.w = frameWidth;
    player->spritePosition.h = frameHeigth;

    player->isOnGround = true;

    //------------ End working with sprite animation ---------------

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

    bool quit = SDL_FALSE;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE) {
                        if(showMenu(renderer, font) == 0) {
                            quit = SDL_TRUE;
                            clearLevel(player, player->texture);
                            return QUIT;
                        }
                        break;
                    }
                    if(event.key.keysym.sym == SDLK_p) {
                        clearLevel(player, player->texture);
                        return FINISH;
                        break;
                    }
                    doKeyDown(&event.key);
                    break;
                case SDL_KEYUP:
                    doKeyUp(&event.key);
                    break;
                default:
                    break;
            }
        }

        // Draw sprite
        SDL_RenderClear(renderer);

        // -----------NEW----------------
        frameTime++;
        doPlayer();
        loadPlayerMoveTexture(renderer, player, moveType, &textureWidth);
        if(FPS / frameTime == 6) {
          frameTime = 0;
          player->spriteRect.x += player->spriteRect.w;
          if((player->spriteRect.x + player->spriteRect.w) >= textureWidth) player->spriteRect.x = 0;
        }

        player->dy += GRAVITY;

        player->dy = MAX(MIN(player->dy, 18), -999);

        SDL_Rect movedRect = {player->spritePosition.x + player->dx, player->spritePosition.y, player->spritePosition.w, player->spritePosition.h};

        if(!checkTileCollisions(&movedRect, level->map, SOLID, level->obstacles)) {
            player->spritePosition.x += player->dx;
        }
        if(checkTileCollisions(&movedRect, level->map, DEATH, level->obstacles)) {
            playerHP = 0;
            clearLevel(player, player->texture);
            return RESTART;
        }
        if(checkTileCollisions(&movedRect, level->map, DAMAGE, level->obstacles)) {
            playerHP--;
            player->spritePosition.x -= player->dx;
            if(playerHP <= 0) {
                clearLevel(player, player->texture);
                return RESTART;
            }
        }
        if(checkTileCollisions(&movedRect, level->map, END, level->obstacles)) {
            clearLevel(player, player->texture);
            return END;
        }

        movedRect.x = player->spritePosition.x;
        movedRect.y = player->spritePosition.y + player->dy;

        if(!checkTileCollisions(&movedRect, level->map, SOLID, level->obstacles)) {
            player->spritePosition.y += player->dy;
        }
        else {
            player->isOnGround = player->dy > 0;
            player->dy = 0;
        }
        if(checkTileCollisions(&movedRect, level->map, DEATH, level->obstacles)) {
            playerHP = 0;
            clearLevel(player, player->texture);
            return RESTART;
        }
        if(checkTileCollisions(&movedRect, level->map, DAMAGE, level->obstacles)) {
            playerHP--;
            player->spritePosition.y -= player->dy;
            if(playerHP <= 0) {
                clearLevel(player, player->texture);
                return RESTART;
            }
        }
        if(checkTileCollisions(&movedRect, level->map, END, level->obstacles)) {
            clearLevel(player, player->texture);
            return END;
        }

        // ------------------------------

        renderLevel(level, renderer);

        SDL_RenderCopy(renderer, player->texture, &player->spriteRect, &player->spritePosition);

        renderHP(renderer, playerHP);
        renderLevelBar(renderer, font, level->number, level->name);


        SDL_RenderPresent(renderer);
    }

    // Free resources
    clearLevel(player, player->texture);
    return FINISH;
}


