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
