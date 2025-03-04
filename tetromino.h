#ifndef TETROMINO_H
#define TETROMINO_H

#include "game.h"

typedef struct {
    int x,y;
    int shape[4][4];
} Tetromino;

extern Tetromino currentPiece;
extern const Tetromino tetrominoes[7];

void newPiece();

#endif