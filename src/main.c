#include "../inc/header.h" 

int main(void) {
	if(initSDL()) {
		int playerHP = 3;

		SDL_Window* window = SDL_CreateWindow("Dark Ages Knight", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    	if(window == NULL) {
        	printf("Window could not be created. SDL Error: %s\n", SDL_GetError());
       		return 1;
    	}

    	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
   		if(renderer == NULL) {
        	printf("Renderer could not be created. SDL Error: %s\n", SDL_GetError());
        	return 1;
    	}

		TTF_Font *font = TTF_OpenFont("resource/fonts/font.ttf", 48);
    	if (font == NULL) {
        	printf("Font could not be loaded: %s\n", TTF_GetError());
        	return 1;
    	}

		Level *levels = initLevels(renderer);

		if(showMenu(renderer, font) == 1) {
			for(int i = 0; i < NUMBER_OF_LEVELS; i++) {
				Mix_PlayMusic(levels[i].music, -1);
				int levelState = startLevel(&levels[i], renderer, levels[i].startX, levels[i].startY, font, playerHP);

				if(levelState == RESTART) {
					i--;
				}
				if(levelState == QUIT) {
					break;
				}
			}

			free(levels);
			for(int i = 0; i < NUMBER_OF_LEVELS; i++) {
				SDL_DestroyTexture(levels[i].background);
			}
			TTF_CloseFont(font);
			clearSDL(renderer, window);
		}
	}
}	


