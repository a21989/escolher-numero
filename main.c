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

int64_t get_random_number(int64_t min, int64_t max) {
    return rand_u64(&seed) % (max + 1 - min) + min;
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

int choose_number(int exit_code) {
    clear_screen_and_move_cursor_to_start();

    seed_rng();

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

    leave_alternate_screen();

    for (int64_t i = 0; i < n; i++) {
        printf("%ld\n", get_random_number(min, max));
    }

    return exit_code;
}

int coin_toss(void) {
    clear_screen_and_move_cursor_to_start();

    seed_rng();

    int64_t number = get_random_number(0, 1);

    bool cara = (bool)number;

    leave_alternate_screen();

    return puts(cara ? "○ cara" : "● coroa");
}

int user_select_start(int previous_exit_code) {
    clear_screen_and_move_cursor_to_start();

    printf("[1] Escolher número(s)\n[2] Mandar uma moeda ao ar (\"cara ou coroa\")\n[q] Sair\n\n");

    if (previous_exit_code == -2)
        printf("Seleção inválida. Insira apenas uma das opções disponíveis.\n\n");

    char c1;
    char c2 = ' ';

    printf("Ação a executar: ");

    if (scanf(" %c%c", &c1, &c2) == 2 && c2 != '\n') {
        scanf("%*[^\n]");
        c1 = 'e';
    }

    switch (c1) {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case 'q':
        return 'q';
        break;
    default:
        return -2;
        break;
    }
}

int main(void) {
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
            ret = choose_number(ret);
        }

        break;
    case 2:
        ret = coin_toss();
        break;
    default:
        leave_alternate_screen();
        break;
    }

    return ret;
}