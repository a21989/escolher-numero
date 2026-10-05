#include <stdlib.h>

#include "interactive.h"
#include "random.h"

#include "choose_number.h"
#include "coin_toss.h"

#include "exit_codes.h"

int main(int argc, char *argv[]) {
    seed_t *seed = (seed_t *)malloc(sizeof(seed_t));

    int ret = EXIT_FAILURE;

    if (argc > 1) {
        ret = handle_args(argc, argv, seed);
    } else {
        ret = interactive(-1, seed);
    }

    free(seed);

    return ret;
}
