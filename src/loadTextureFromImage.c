#include "../inc/header.h"

SDL_Texture* loadTextureFromImage(SDL_Renderer* renderer, const char *filePath) {
    
    SDL_Surface* surface = IMG_Load(filePath);
	if (surface == NULL) {
        printf("Failed to load image. SDL_image Error: %s\n", IMG_GetError());
       	return NULL;
    }
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
    	
    return texture;
}


