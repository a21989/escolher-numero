#ifndef CHOOSE_NUMBER_H
#define CHOOSE_NUMBER_H

#include "random.h"

void print_random_numbers(int64_t min, int64_t max, int64_t n, seed_t *seed);

int choose_number(seed_t *seed, int exit_code);

#endif
