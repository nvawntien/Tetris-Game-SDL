#include "game.h"


int grid[GRID_HEIGHT][GRID_WIDTH];

void initGame() {
    srand(time(NULL));
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            grid[y][x] = 0;
        }
    }

    newPiece();
}

void updateGame() {
    static Uint32 lastUpdate = 0;
    Uint32 currentTime = SDL_GetTicks();

    if (currentTime - lastUpdate > 1000) {
        Tetromino piece = currentPiece;
        piece.y++;
        currentPiece = piece;
        lastUpdate = currentTime;
    }
}
