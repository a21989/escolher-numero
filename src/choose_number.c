#include "escape_codes.h"
#include "random.h"
#include <inttypes.h>
#include <stdio.h>

void print_random_numbers(int64_t min, int64_t max, int64_t n, seed_t *seed) {
    for (int64_t i = 0; i < n; i++) {
        printf("%ld\n", get_random_number(min, max, seed));
    }
}

int choose_number(seed_t *seed, int exit_code) {
    clear_screen_and_move_cursor_to_start();

    seed_rng(seed);

    if (exit_code > 0)
        printf("Valores inseridos inválidos.\n\n");

    exit_code = 0;

    printf("Quantidade de números a obter: ");

    int ret;
    char c = ' ';

    int64_t n;

    ret = scanf("%ld%c", &n, &c);

    if (ret == 0 || (ret == 2 && c != '\n')) {
        exit_code += 1;
    }

    if (ret < 1) {
        scanf("%*[^\n]");
    }

    printf("Valor mínimo inclusivo: ");

    int64_t min;

    ret = scanf("%ld%c", &min, &c);

    if (ret < 1 || (ret == 2 && c != '\n')) {
        exit_code += 1;
    }

    if (ret < 1) {
        scanf("%*[^\n]");
    }

    printf("Valor máximo inclusivo: ");

    int64_t max;

    ret = scanf("%ld%c", &max, &c);

    if (ret == 0 || (ret == 2 && c != '\n')) {
        exit_code += 1;
    }

    if (ret < 1) {
        scanf("%*[^\n]");
    }

    if (min > max) {
        exit_code += 1;
    }

    if (exit_code > 0)
        return exit_code;

    enable_line_buffer();
    leave_alternate_screen();

    print_random_numbers(min, max, n, seed);

    return exit_code;
}
