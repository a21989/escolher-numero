#ifndef RANDOM_H
#define RANDOM_H

#include "random/rand_u64.h"

typedef rand_u64_gen_t seed_t;

void seed_rng(seed_t *seed);

int64_t get_random_number(int64_t min, int64_t max, rand_u64_gen_t *seed);

#endif
