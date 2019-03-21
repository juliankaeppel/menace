#ifndef STATE_H
#define STATE_H

#define NUM_STATES 3
#define NUM_BOXES 9
#define STARTING_WEIGHT 5

#include <stdbool.h>
#include <stdio.h>

// Stores the weights of each choice for the stored board
typedef struct state {
    // The state of the board stored in base-3
    unsigned short board;
    // The weight of each box being chosen
    // A weight of zero means the box is either
    // filled or has been eliminated
    unsigned int weight[NUM_BOXES];
    // The number of weights(beads)
    unsigned long num_weights;
    // Flag set if state is used in current game
    bool used;
    // Move that was played with this state
    unsigned char move;
} state;

// Returns the state of a box on the board of state s
unsigned char get_box_state(state* s, unsigned char pos);

// Returns the resulting board state after a move
unsigned short new_box_state(state* s, unsigned char pos, unsigned char value);

// Updates num_weights
void calibrate_weights(state* s);

// Sets the weights of a new board
void init_weights(state* s);

// Display board
void print_board(state* s);

#endif