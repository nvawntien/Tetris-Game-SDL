#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include "tetromino.h"
#include <SDL2/SDL.h>


#define SCREEN_WIDTH 800
#define SCREEN_HEIGTH 600
#define WINDOW_TITLE "Tetris"
#define GRID_WIDTH 10
#define GRID_HEIGHT 20
#define BLOCK_SIZE 25

extern int grid[GRID_HEIGHT][GRID_WIDTH];

void initGame();
void updateGame();
void handleInput(SDL_Event event);

#endif