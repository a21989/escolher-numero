#ifndef CHOOSE_NUMBER_H
#define CHOOSE_NUMBER_H

#include "random.h"

void print_random_numbers(int64_t n, int64_t min, int64_t max, seed_t *seed);

int choose_number(seed_t *seed, int exit_codes);

#endif
