#include "../inc/header.h"

void renderHP(SDL_Renderer* renderer, int playerHP) {
	SDL_Surface* hpSurface = IMG_Load("resource/img/hp.png");
	
	for(int i = 0; i < playerHP; i++) {
		SDL_Texture* hpTexture = SDL_CreateTextureFromSurface(renderer, hpSurface);
		SDL_Rect hpRect = {i * hpSurface->w / 12 + DISPLAY_TILE_SIZE, DISPLAY_TILE_SIZE, hpSurface->w / 12, hpSurface->h / 12};
		
		SDL_RenderCopy(renderer, hpTexture, NULL, &hpRect);

		SDL_DestroyTexture(hpTexture);
	}
	SDL_FreeSurface(hpSurface);
}


