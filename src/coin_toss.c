#include "escape_codes.h"
#include "random.h"
#include <inttypes.h>
#include <stdio.h>

int coin_toss(seed_t *seed) {
    clear_screen_and_move_cursor_to_start();

    seed_rng(seed);

    int64_t number = get_random_number(0, 1, seed);

    bool cara = (bool)number;

    leave_alternate_screen();

    return puts(cara ? "○ cara" : "● coroa");
}
