#include "state.h"

unsigned char get_box_state(state* s, unsigned char pos) {
    // The number to divide the board by to get
    // the box state
    unsigned short power;

    for (power = 1; pos > 0; pos--) power *= NUM_STATES;

    return s->board / power % NUM_STATES;
}

unsigned short new_box_state(state* s, unsigned char pos, unsigned char value) {
    // The number to divide the board by to get
    // the box state
    unsigned short power;

    for (power = 1; pos > 0; pos--) power *= NUM_STATES;

    return s->board + value * power;
}

void calibrate_weights(state* s) {
    s->num_weights = 0;

    for (unsigned char i = 0; i < NUM_BOXES; i++)
        s->num_weights += s->weight[i];
}

void init_weights(state* s) {
    s->num_weights = 0;

    // Sets weight to zero if the box is already filled,
    // otherwise sets it to the starting weight
    for (unsigned char i = 0; i < NUM_BOXES; i++) {
        if (get_box_state(s, i) == 0) {
            s->weight[i] = STARTING_WEIGHT;
            s->num_weights += STARTING_WEIGHT;
        } else {
            s->weight[i] = 0;
        }
    }
}

void print_board(state* s) {
    printf("Board:\n%d|%d|%d\n-----\n%d|%d|%d\n-----\n%d|%d|%d\n\n",
        get_box_state(s, 0),
        get_box_state(s, 1),
        get_box_state(s, 2),
        get_box_state(s, 3),
        get_box_state(s, 4),
        get_box_state(s, 5),
        get_box_state(s, 6),
        get_box_state(s, 7),
        get_box_state(s, 8)
    );
}