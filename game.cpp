#include "game.h"


int grid[GRID_HEIGHT][GRID_WIDTH] = {0};

void initGame() {
    srand(time(NULL));
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            grid[y][x] = 0;
        }
    }

    newPiece();
}
