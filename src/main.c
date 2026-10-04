#include <stdio.h>
#include <stdlib.h>

#include "interactive.h"
#include "random.h"

int main(void) {
    seed_t *seed = (seed_t *)malloc(sizeof(seed_t));

    int ret;

    ret = interactive(seed);

    free(seed);

    return ret;
}
