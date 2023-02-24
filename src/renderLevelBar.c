#include "../inc/header.h"

void renderLevelBar(SDL_Renderer* renderer, TTF_Font* font, int currentLevel, const char* levelName) {
    SDL_Color color = {0xFF, 0xFF, 0xFF, 0};
    char text[80] = "Level: ";
	strcat(text, intToString(currentLevel));
    strcat(text, " ~ ");
    strcat(text, levelName);
    
    SDL_Surface* levelBar = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* levelBarTexture = SDL_CreateTextureFromSurface(renderer, levelBar);
    SDL_Rect levelBarRect = {SCREEN_WIDTH / 2 - levelBar->w / 2, DISPLAY_TILE_SIZE, levelBar->w, levelBar->h};

	SDL_RenderCopy(renderer, levelBarTexture, NULL, &levelBarRect);

	SDL_DestroyTexture(levelBarTexture);

	SDL_FreeSurface(levelBar);
}

