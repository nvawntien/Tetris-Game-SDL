#include "render.h"


const int gridOffsetX = (SCREEN_WIDTH - GRID_WIDTH * BLOCK_SIZE) / 2;

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

void drawGridLines(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    for (int x = 0; x <= GRID_WIDTH; x++) {
        int screenX = gridOffsetX + x * BLOCK_SIZE;
        SDL_RenderDrawLine(renderer, screenX, 0, screenX, GRID_HEIGHT * BLOCK_SIZE);
    }

    for (int y = 0; y <= GRID_HEIGHT; y++) {
        int screenY = y * BLOCK_SIZE;
        SDL_RenderDrawLine(renderer, gridOffsetX, screenY, gridOffsetX + GRID_WIDTH * BLOCK_SIZE, screenY);
    }
}

void renderGame(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    drawGridLines(renderer);
    SDL_RenderPresent(renderer);
}