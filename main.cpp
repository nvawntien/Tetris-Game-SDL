/*
	author: n.vantien
	from: University of Engineering and Technology
*/

#include "utils.h"
#include "render.h"

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    initRenderer(&window, &renderer);

    bool running = true;
    SDL_Event event;
    
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            // ... event input
        }
        
        renderGame(renderer);
    }

    closeRenderer(window, renderer);
    return 0;
}