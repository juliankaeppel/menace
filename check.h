#ifndef CHECK_H
#define CHECK_H

#include <stdbool.h>
#include "state.h"

// Returns the state of the board as:
// 0: unfinished
// 1: player 1 wins
// 2: player 2 wins
// 3: draw
unsigned char check_board_state(state* s);

// Check if three boxes have the same state
bool check_row_condition(state* s, unsigned char p1, unsigned char p2, unsigned char p3);

#endif