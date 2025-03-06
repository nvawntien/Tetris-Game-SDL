#include "render.h"

const int gridOffsetX = (SCREEN_WIDTH - GRID_WIDTH * BLOCK_SIZE) / 2;
const int gridOffSetY = (SCREEN_HEIGTH - GRID_HEIGHT * BLOCK_SIZE) / 2;

void drawBackground(SDL_Renderer* renderer, SDL_Texture* backgroundTexture) {
    if (backgroundTexture) {
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
    }
}

void drawMatrix(SDL_Renderer* renderer, SDL_Texture* matrix) {
    if (matrix) {
        SDL_Rect matrixRect = {gridOffsetX, gridOffSetY, BLOCK_SIZE * GRID_WIDTH, BLOCK_SIZE * GRID_HEIGHT};  // Điều chỉnh theo tọa độ mong muốn
        SDL_RenderCopy(renderer, matrix, NULL, &matrixRect);
    }
}

void drawBlock(SDL_Renderer* renderer, int x, int y, SDL_Color color) {
    int screenX = gridOffsetX + x * BLOCK_SIZE;
    int screenY = gridOffSetY + y * BLOCK_SIZE;

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

void renderGame(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, SDL_Texture* matrix) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    drawBackground(renderer, backgroundTexture);
    drawMatrix(renderer, matrix);
    drawGrid(renderer);
    drawPiece(renderer, currentPiece);
    SDL_RenderPresent(renderer);
}