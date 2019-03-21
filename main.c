#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "menace.h"
#include "check.h"

#define ITERATIONS 1000

int main() {
    srand(time(NULL));

    menace menace_1;
    menace menace_2;

    init_menace(&menace_1, 1);
    init_menace(&menace_2, 2);

    for (int i = 0; i < ITERATIONS; i++) {
        state active_state;
        active_state.board = 0;
        active_state.used = false;
        init_weights(&active_state);

        if (i == ITERATIONS - 1)
            print_board(&active_state);

        // stop once game is over
        while (check_board_state(&active_state) == 0) {
            add_state(&menace_1, active_state);
            active_state = select_move(&menace_1, active_state);

            if (i == ITERATIONS - 1)
                print_board(&active_state);

            if (check_board_state(&active_state) != 0)
                break;

            add_state(&menace_2, active_state);
            active_state = select_move(&menace_2, active_state);

            if (i == ITERATIONS - 1)
                print_board(&active_state);
        }

        printf("%d: ", i);

        switch (check_board_state(&active_state)) {
        case 0:
            printf("horribly castastrophic event occurred\n");
            break;
        case 1:
            printf("menace_1 won\n");
            update_weights(&menace_1, WIN);
            update_weights(&menace_2, LOSE);
            break;
        case 2:
            printf("menace_2 won\n");
            update_weights(&menace_1, LOSE);
            update_weights(&menace_2, WIN);
            break;
        case 3:
            printf("draw\n");
            update_weights(&menace_1, DRAW);
            update_weights(&menace_2, DRAW);
            break;
        }
    }

    free(menace_1.states);
    free(menace_2.states);
}