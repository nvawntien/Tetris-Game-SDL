#include "utils.h"

void logSDLError(const std :: string msg, bool fatal) {
    std :: cerr << msg << "Error:" << SDL_GetError();
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initRenderer(SDL_Window** window, SDL_Renderer** renderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) logSDLError("Init", true);
    IMG_Init(IMG_INIT_PNG);
    *window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN);
    if (*window == nullptr) logSDLError("CreateWindow", true);
    
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == nullptr) logSDLError("CreateRenderer", true);
}

void loadImage(SDL_Renderer* renderer, const char* path, SDL_Texture** image) {
    SDL_Surface* surface = IMG_Load(path); 
    *image = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void closeRenderer(SDL_Window* window, SDL_Renderer* renderer, SDL_Texture* backgroundTexture, SDL_Texture* matrix) {
    SDL_DestroyTexture(matrix);
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}