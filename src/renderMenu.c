#include "../inc/header.h"

void renderMenu(SDL_Renderer* renderer, TTF_Font* font, int selectedItem, const char** MENU_ITEMS) {
    // Clear the screen
    SDL_RenderClear(renderer);

	// Load and render background image

	SDL_Texture* backgTexture = loadTextureFromImage(renderer, "resource/img/menu/menu_background.png");
	SDL_Rect backgRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

	SDL_RenderCopy(renderer, backgTexture, NULL, &backgRect);

	// Load and render menu logo
	SDL_Surface* backgLogo = IMG_Load("resource/img/menu/menu_logo.png");
	if (backgLogo == NULL) {
    	printf("Failed to load logo image. SDL_image Error: %s\n", IMG_GetError());
		return;
	}
	SDL_Texture* backgLogoTexture = SDL_CreateTextureFromSurface(renderer, backgLogo);
	SDL_Rect backgLogoRect = {SCREEN_WIDTH / 2 - (backgLogo->w / 3), SCREEN_HEIGHT / 5 - 170, backgLogo->w / 1.5, backgLogo->h / 1.5};;
	
	SDL_RenderCopy(renderer, backgLogoTexture, NULL, &backgLogoRect);

	SDL_FreeSurface(backgLogo);
	SDL_DestroyTexture(backgTexture);
	SDL_DestroyTexture(backgLogoTexture);

    // Render the menu items
    for (int i = 0; i < MENU_ITEM_COUNT; i++) {
        SDL_Color color = {0xFF, 0xFF, 0xFF, 0};
        if(i == selectedItem) {
            color.r = 0xFF;
            color.g = 0x00;
            color.b = 0x00;
        }

        SDL_Surface* surface = TTF_RenderText_Solid(font, MENU_ITEMS[i], color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        int x = SCREEN_WIDTH / 2 - surface->w / 2;
        int y = SCREEN_HEIGHT / 2 - 50 + i - 50 + i * 50;
        SDL_Rect dstrect = { x, y, surface->w, surface->h };
		
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}
	// Update the screen
	SDL_RenderPresent(renderer);
}

