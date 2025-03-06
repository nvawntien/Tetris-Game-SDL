/*
	author: n.vantien
	from: University of Engineering and Technology
*/

#include "utils.h"
#include "render.h"
#include "game.h"

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* backgroundTexture = nullptr, *matrix = nullptr;

    initRenderer(&window, &renderer);
    loadImage(renderer, "img/background.png", &backgroundTexture);
    loadImage(renderer, "img/matrix.png", &matrix);
    initGame();

    bool running = true;
    SDL_Event event;
    
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            // ... event input 
        }
            
        updateGame();
        renderGame(renderer, backgroundTexture, matrix);
    }
    
    closeRenderer(window, renderer, backgroundTexture, matrix);
    return 0;
}