#ifndef MENACE_H
#define MENACE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "state.h"

// Stores a pointer array of states along with the size
typedef struct menace {
    state* states;
    size_t states_size;
    unsigned char turn;
} menace;

typedef enum WIN_CONDITION {
    WIN,
    LOSE,
    DRAW
} WIN_CONDITION;

// Initialize instance of menace
void init_menace(menace* m, unsigned char turn);

// Add state and increase size
void add_state(menace* m, state s);

// Pick move based on current board and weights
// and return updated state
state select_move(menace* m, state s);

// After the game is finished, update weights
void update_weights(menace* m, WIN_CONDITION condition);

#endif