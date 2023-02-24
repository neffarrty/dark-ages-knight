#include "../inc/header.h"

void clearSDL(SDL_Renderer* renderer, SDL_Window* window) {
    SDL_DestroyRenderer(renderer);
	renderer = NULL;
    SDL_DestroyWindow(window);
	window = NULL;
	
	Mix_CloseAudio();
	Mix_Quit();
    IMG_Quit();
	TTF_Quit();
    SDL_Quit();
}
