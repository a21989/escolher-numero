#include "random/rand_seed.h"
#include "random/rand_u64.h"

rand_u64_gen_t seed;

void seed_rng() {
    rand_state_init(time(NULL), seed.state, 16);
}

int64_t get_random_number(int64_t min, int64_t max) {
    return rand_u64(&seed) % (max + 1 - min) + min;
}
