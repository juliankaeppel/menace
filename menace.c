#include "menace.h"

void init_menace(menace* m, unsigned char turn) {
    m->states = malloc(0);
    m->states_size = 0;
    m->turn = turn;
}

void add_state(menace* m, state s) {
    m->states = realloc(m->states, ++m->states_size * sizeof(state));
    m->states[m->states_size - 1] = s;
}

state select_move(menace* m, state s) {
    // Index of matching stored state
    size_t index = 0;
    // Whether or not a state already exists
    bool exists = false;
    
    for (; index < m->states_size; index++) {
        if (m->states[index].board == s.board) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        init_weights(&s);
        add_state(m, s);
        index = m->states_size - 1;
    }

    // The exact weight/bead to use, unsorted
    long weight_index = rand() % m->states[index].num_weights;

    // Find the box to use from the random weight
    for (unsigned char box = 0; box < NUM_BOXES; box++) {
        weight_index -= m->states[index].weight[box];
        if (weight_index <= 0) {
            s.board = new_box_state(&s, box, m->turn);
            m->states[index].used = true;
            m->states[index].move = box;
            init_weights(&s);
            s.used = false;
            return s;
        }
    }

    // This happens if weight_index never goes below zero
    printf("Weight index improperly allocated: %d\n", weight_index);
    exit(1);
}

void update_weights(menace* m, WIN_CONDITION condition) {
    for (size_t i = 0; i < m->states_size; i++) {
        if (m->states[i].used) {
            switch(condition) {
                case WIN:
                    m->states[i].weight[m->states[i].move]++;
                    break;
                case LOSE:
                    m->states[i].weight[m->states[i].move]--;
                    break;
            }
            calibrate_weights(&m->states[i]);
            if (m->states[i].num_weights == 0)
                init_weights(&m->states[i]);
        }
    }
}