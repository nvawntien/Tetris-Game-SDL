#ifndef UTILS_H
#define UTILS_H
#include <SDL2/SDL.h>
#include <iostream>
#include "game.h"

void logSDLError(const std :: string msg, bool fatal);
void initRenderer(SDL_Window** window, SDL_Renderer** renderer);
void closeRenderer(SDL_Window* window, SDL_Renderer* renderer);

#endif