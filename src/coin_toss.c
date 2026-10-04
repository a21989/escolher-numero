#include "escape_codes.h"
#include "random.h"
#include <inttypes.h>
#include <stdio.h>

int coin_toss(seed_t *seed, bool in_alternate_screen) {
    seed_rng(seed);

    int64_t number = get_random_number(0, 1, seed);

    bool cara = (bool)number;

    if (in_alternate_screen)
        leave_alternate_screen();

    return puts(cara ? "○ cara" : "● coroa");
}
