#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include "random.h"

int interactive(int mode, seed_t *seed);

int handle_args(int argc, char *argv[], seed_t *seed);

#endif