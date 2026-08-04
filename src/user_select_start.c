#include "escape_codes.h"
#include <stdio.h>

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
