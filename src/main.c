#include <stdio.h>
#include <stdlib.h>

#include "random.h"

#include "escape_codes.h"

#include "choose_number.h"

#include "coin_toss.h"

#include "user_select_start.h"

int main(void) {
    seed_t *seed = (seed_t *)malloc(sizeof(seed_t));

    enter_alternate_screen();

    int ret;

    ret = -1;

    while (ret < 0) {
        ret = user_select_start(ret);
    }

    switch (ret) {
    case 1:
        int ret = -1;

        while (ret != 0) {
            ret = choose_number(seed, ret);
        }

        break;
    case 2:
        ret = coin_toss(seed);
        break;
    default:
        leave_alternate_screen();
        break;
    }

    free(seed);

    return ret;
}
