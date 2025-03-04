#include "render.h"

const int gridOffsetX = (SCREEN_WIDTH - GRID_WIDTH * BLOCK_SIZE) / 2;

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

void drawBlock(SDL_Renderer* renderer, int x, int y, SDL_Color color) {
    int screenX = gridOffsetX + x * BLOCK_SIZE;
    int screenY = y * BLOCK_SIZE;

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {screenX, screenY, BLOCK_SIZE, BLOCK_SIZE};
    SDL_RenderFillRect(renderer, &rect);
} 

void drawGrid(SDL_Renderer* renderer) {
    SDL_Color color= {255, 0, 0, 255};

    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            if (grid[y][x]){
                drawBlock(renderer, x, y, color);
            }
        }
    }
}

void drawPiece(SDL_Renderer* renderer, Tetromino piece) {
    SDL_Color color = {255, 0, 0, 255};

    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            if (piece.shape[x][y]) {
                drawBlock(renderer, piece.x + x, piece.y + y,color);
            }
        }
    }
}

void renderGame(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    drawGridLines(renderer);
    drawGrid(renderer);
    drawPiece(renderer, currentPiece);
    SDL_RenderPresent(renderer);
}