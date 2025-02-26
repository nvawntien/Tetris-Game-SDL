#include "render.h"

void logSDLError(const std :: string msg, bool fatal) {
    std :: cerr << msg << "Error:" << SDL_GetError();
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initRenderer(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) logSDLError("Init", true);
    
    *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN);
    if (*window == nullptr) logSDLError("CreateWindow", true);
    
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == nullptr) logSDLError("CreateRenderer", true);
}

void closeRenderer(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void renderGame(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}