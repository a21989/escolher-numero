#include "random/rand_seed.h"
#include "random/rand_u64.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "random.c"

#include "escape_codes.c"

#include "choose_number.c"

#include "coin_toss.c"

#include "user_select_start.c"

int main(void) {
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
            ret = choose_number(ret);
        }

        break;
    case 2:
        ret = coin_toss();
        break;
    default:
        leave_alternate_screen();
        break;
    }

    return ret;
}
