#include "deps/random/rand_seed.h"
#include "deps/random/rand_u64.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

rand_u64_gen_t seed;

void seed_rng() {
    rand_state_init(time(NULL), seed.state, 16);
}

int64_t *get_random_numbers(int64_t n, int64_t min, int64_t max) {
    int64_t *num_array = (int64_t *)malloc(sizeof(int64_t) * n);

    for (int64_t i = 0; i < n; i++) {
        num_array[i] = rand_u64(&seed) % (max + 1 - min) + min;
    }

    return num_array;
}

// https://en.wikipedia.org/wiki/ANSI_escape_code

void clear_screen_and_move_cursor_to_start() {
    printf("\033[2J\033[H");
}

void enter_alternate_screen() {
    printf("\033[?1049h");
}

void leave_alternate_screen() {
    printf("\033[?1049l");
}

int choose_number(char **result_to_print, int previous_exit_code) {
    clear_screen_and_move_cursor_to_start();

    int exit_code = 0;

    seed_rng();

    if (previous_exit_code > 0)
        printf("Valores inseridos inválidos.\n\n");

    printf("Quantidade de números a obter: ");

    int ret;

    int64_t n;

    ret = scanf("%ld", &n);

    if (ret < 1) {
        exit_code += 1;
    }

    printf("Valor mínimo inclusivo: ");

    int64_t min;

    ret = scanf("%ld", &min);

    if (ret < 1) {
        exit_code += 1;
    }

    printf("Valor máximo inclusivo: ");

    int64_t max;

    ret = scanf("%ld", &max);

    if (ret < 1) {
        exit_code += 1;
    }

    if (exit_code > 0)
        return exit_code;

    int64_t *numbers = get_random_numbers(n, min, max);

    char *numbers_string = (char *)malloc(21 * sizeof(char) * n); // at most, each number will occupy a string of 21 characters

    int_fast16_t string_offset = 0;

    for (int64_t i = 0; i < n; i++) {
        // string_offset = strlen(*result_to_print);

        string_offset += sprintf(&numbers_string[string_offset], "%ld\n", numbers[i]);
    }

    *result_to_print = numbers_string;

    return exit_code;
}

int coin_toss(char **result_to_print) {
    clear_screen_and_move_cursor_to_start();

    seed_rng();

    int n = 1;
    int min = 0;
    int max = 1;

    int64_t *num_array = get_random_numbers(n, min, max);

    bool cara = (bool)num_array[n - 1];

    free(num_array);

    *result_to_print = cara ? "○ cara" : "● coroa";

    return 0;
}

int user_select_start(int previous_exit_code) {
    clear_screen_and_move_cursor_to_start();

    printf("Que ação pretende executar?\n\n1: Escolher número(s)\n2: Mandar uma moeda ao ar (\"cara ou coroa\")\n\n");

    if (previous_exit_code == 4)
        printf("Invalid code.\n\n");

    char c;

    scanf(" %c", &c);

    switch (c) {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case 'q':
        return 3;
        break;
    default:
        return 4;
        break;
    }
}

int main(void) {
    enter_alternate_screen();

    int user_select_start_return_code;

    user_select_start_return_code = -1;

    while (user_select_start_return_code < 0 || user_select_start_return_code == 4) {
        user_select_start_return_code = user_select_start(user_select_start_return_code);
    }

    char *result_to_print;

    switch (user_select_start_return_code) {
    case 1:
        int choose_number_return_code = -1;

        while (choose_number_return_code != 0) {
            choose_number_return_code = choose_number(&result_to_print, choose_number_return_code);
        }

        break;
    case 2:
        coin_toss(&result_to_print);

        break;
    default:
        break;
    }

    leave_alternate_screen();

    puts(result_to_print);

    if (user_select_start_return_code == 1)
        free(result_to_print);

    return 0;
}