#include <inttypes.h>

int coin_toss(void) {
    clear_screen_and_move_cursor_to_start();

    seed_rng();

    int64_t number = get_random_number(0, 1);

    bool cara = (bool)number;

    leave_alternate_screen();

    return puts(cara ? "○ cara" : "● coroa");
}
