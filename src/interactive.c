#include <stdio.h>
#include <string.h>

#include "random.h"

#include "choose_number.h"
#include "coin_toss.h"
#include "escape_codes.h"
#include "user_select_start.h"

int interactive(int mode, seed_t *seed) {
    disable_buffer();
    enter_alternate_screen();

    int ret = -1;

    while (mode < 0) {
        mode = user_select_start(mode);
    }

    switch (mode) {
    case 1:
        ret = -1;

        while (ret != 0) {
            ret = choose_number(seed, ret);
        }

        break;
    case 2:
        ret = coin_toss(seed, true);
        break;
    default:
        leave_alternate_screen();
        break;
    }

    return ret;
}

int handle_args(int argc, char *argv[], seed_t *seed) {
    int ret = 0;

    /* argc = 1          2          3          4          5
     *        argv[0]    argv[1]    argv[2]    argv[3]    argv[4]
     *        "./..."    mode=1|2         n        min        max
     */

    if (strcmp(argv[1], "1") == 0) {
        if (argc < 3) {
            ret = interactive(1, seed);
        } else if (argc < 5) {
            fprintf(stderr, "Argumentos insuficientes\n");

            ret = 1;
        } else if (argc >= 5) {
            int64_t n = atoll(argv[2]);
            int64_t min = atoll(argv[3]);
            int64_t max = atoll(argv[4]);

            if (min > max) {
                fprintf(stderr, "Argumentos inválidos: O número máximo não pode ser menor que o número mínimo.\n");

                ret = 1;
            } else {
                seed_rng(seed);
                print_random_numbers(min, max, n, seed);
            }
        }
    } else if (strcmp(argv[1], "2") == 0) {
        ret = coin_toss(seed, false);
    }

    return ret;
}
