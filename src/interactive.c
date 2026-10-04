#include "random.h"

#include "choose_number.h"
#include "coin_toss.h"
#include "escape_codes.h"
#include "user_select_start.h"

int interactive(seed_t *seed) {
    disable_buffer();
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
        ret = coin_toss(seed, true);
        break;
    default:
        leave_alternate_screen();
        break;
    }

    return ret;
}