#include "deps/random/rand_seed.h"
#include "deps/random/rand_u64.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

rand_u64_gen_t seed;

void seed_rng() {
    rand_state_init(time(NULL), seed.state, 16);
}

int64_t get_random_number(int64_t min, int64_t max) {
    return rand_u64(&seed) % (max + 1 - min) + min;
}

void clear_screen_and_move_cursor_to_start() {
    printf("\033[2J\033[H");
}

// https://en.wikipedia.org/wiki/ANSI_escape_code
void enter_alternate_screen() {
    printf("\033[?1049h"); // Enter alternate screen
}

void leave_alternate_screen() {
    printf("\033[?1049l"); // Leave alternate screen
}

void choose_number(void) {
    seed_rng();
}

void coin_toss(void) {
    seed_rng();
}

int main(void) {
    bool invalid_command_already_triggered = false;

    enter_alternate_screen();

    printf("Que ação pretende executar?\n\n1: Escolher número(s)\n2: Mandar uma moeda ao ar (\"cara ou coroa\")\n\n");

    char c;

before_scanf:

    scanf(" %c", &c);

    switch (c) {
    case 'q':
        goto leave;
        break;
    case '1':
        choose_number();
        break;
    case '2':
        coin_toss();
        break;
    default:
        if (!invalid_command_already_triggered) {
            printf("\33[1A");
            printf("\33[2K\r");
            printf("Invalid command.\n\n");
        } else {
            clear_screen_and_move_cursor_to_start();
        }
        invalid_command_already_triggered = true;
        goto before_scanf;
        break;
    }

leave:
    leave_alternate_screen();

    printf("You entered: %c\n", c);

    //

    printf("%lu\n", get_random_number(1, 30));
    printf("%lu\n", get_random_number(1, 30));
    printf("%lu\n", get_random_number(1, 30));
    printf("%lu\n", get_random_number(1, 30));
    printf("%lu\n", get_random_number(1, 30));
    printf("%lu\n", get_random_number(1, 30));
    printf("%lu\n", get_random_number(1, 30));

    return 0;
}