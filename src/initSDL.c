#include "../inc/header.h"

bool initSDL(void) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not be initialized. SDL Error: %s\n", SDL_GetError());
        return false;
    }
    	
    int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		printf("SDL_image could not be initialized. SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

	if (TTF_Init() == -1) {
        printf("TTF could not be initialized: %s\n", TTF_GetError());
        return false;
    }

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("MIX could not be initialized: %s\n", Mix_GetError());
        return false;
	}
    	
    return true;
}


