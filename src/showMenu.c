#include "../inc/header.h"

int showMenu(SDL_Renderer* renderer, TTF_Font* font) {
	int selectedItem = 0;
	const char **MENU_ITEMS = (const char**)malloc(MENU_ITEM_COUNT * sizeof(const char*));
	if (MENU_ITEMS == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }

    // Initialize the menu items
    MENU_ITEMS[0] = "Start Game";
    MENU_ITEMS[1] = "Quit";

	Mix_Music* menuMusic = Mix_LoadMUS("resource/music/menu-music.mp3");
	Mix_Chunk* choiceEffect = Mix_LoadWAV("resource/music/choice.wav");
	
	if(menuMusic == NULL || choiceEffect == NULL) {
		printf("Failed to load music file: %s\n", Mix_GetError());
		return 0;
	}

	SDL_Event e;
	bool quit = false;
	Mix_PlayMusic(menuMusic, -1);
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			} 
			else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					selectedItem--;
					if (selectedItem < 0) {
						selectedItem = MENU_ITEM_COUNT - 1;
					}
					Mix_PlayChannel(-1, choiceEffect, 0);
					break;
				case SDLK_DOWN:
					selectedItem++;
					if (selectedItem >= MENU_ITEM_COUNT) {
						selectedItem = 0;
					}
					Mix_PlayChannel(-1, choiceEffect, 0);
					break;
				case SDLK_RETURN:
					if (selectedItem == 1) {
						quit = true;
					}
					else if(selectedItem == 0) {
						Mix_FreeMusic(menuMusic);
						Mix_FreeChunk(choiceEffect);
						return 1;
					}
					break;
				}
			}
		}
    	// Render the menu
    	renderMenu(renderer, font, selectedItem, MENU_ITEMS);
	}
	Mix_FreeMusic(menuMusic);
	Mix_FreeChunk(choiceEffect);
	return 0;
}


