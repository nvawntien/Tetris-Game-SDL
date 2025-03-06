#ifndef RENDER_H
#define RENDER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "game.h"
#include "tetromino.h"

extern const int gridOffsetX;
extern const int gridOffSetY;

void renderGame(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, SDL_Texture* matrix);

#endif 
