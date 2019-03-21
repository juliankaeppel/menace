#include "check.h"

unsigned char check_board_state(state* s) {
    if ((get_box_state(s, 0) == 1 && check_row_condition(s, 0, 1, 2)) ||
        (get_box_state(s, 3) == 1 && check_row_condition(s, 3, 4, 5)) ||
        (get_box_state(s, 6) == 1 && check_row_condition(s, 6, 7, 8)) ||
        (get_box_state(s, 0) == 1 && check_row_condition(s, 0, 3, 6)) ||
        (get_box_state(s, 1) == 1 && check_row_condition(s, 1, 4, 7)) ||
        (get_box_state(s, 2) == 1 && check_row_condition(s, 2, 5, 8)) ||
        (get_box_state(s, 0) == 1 && check_row_condition(s, 0, 4, 8)) ||
        (get_box_state(s, 2) == 1 && check_row_condition(s, 2, 4, 6)))
    {
        return 1;
    }

    if ((get_box_state(s, 0) == 2 && check_row_condition(s, 0, 1, 2)) ||
        (get_box_state(s, 3) == 2 && check_row_condition(s, 3, 4, 5)) ||
        (get_box_state(s, 6) == 2 && check_row_condition(s, 6, 7, 8)) ||
        (get_box_state(s, 0) == 2 && check_row_condition(s, 0, 3, 6)) ||
        (get_box_state(s, 1) == 2 && check_row_condition(s, 1, 4, 7)) ||
        (get_box_state(s, 2) == 2 && check_row_condition(s, 2, 5, 8)) ||
        (get_box_state(s, 0) == 2 && check_row_condition(s, 0, 4, 8)) ||
        (get_box_state(s, 2) == 2 && check_row_condition(s, 2, 4, 6)))
    {
        return 2;
    }

    if (get_box_state(s, 0) != 0 &&
        get_box_state(s, 1) != 0 &&
        get_box_state(s, 2) != 0 &&
        get_box_state(s, 3) != 0 &&
        get_box_state(s, 4) != 0 &&
        get_box_state(s, 5) != 0 &&
        get_box_state(s, 6) != 0 &&
        get_box_state(s, 7) != 0 &&
        get_box_state(s, 8) != 0)
    {
        return 3;
    }

    return 0;
}

bool check_row_condition(state* s, unsigned char p1, unsigned char p2, unsigned char p3) {
    if (get_box_state(s, p1) == get_box_state(s, p2) &&
        get_box_state(s, p2) == get_box_state(s, p3))
    {
        return true;
    }

    return false;
}