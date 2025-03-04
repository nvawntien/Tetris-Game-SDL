#ifndef RENDER_H
#define RENDER_H
#include <SDL2/SDL.h>
#include <iostream>
#include "game.h"
#include "tetromino.h"

extern const int gridOffsetX;
void renderGame(SDL_Renderer* renderer);

#endif 
