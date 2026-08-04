#include "random.h"
#include "random/rand_u64.h"

void seed_rng(seed_t *rng) {
    rand_u64_init(rng);
}

int64_t get_random_number(int64_t min, int64_t max, seed_t *rng) {
    return rand_u64(rng) % (max + 1 - min) + min;
}
