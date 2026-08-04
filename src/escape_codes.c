// https://en.wikipedia.org/wiki/ANSI_escape_code
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

void clear_screen_and_move_cursor_to_start() {
    printf("\033[2J\033[H");
}

void enter_alternate_screen() {
    printf("\033[?1049h");
}

void leave_alternate_screen() {
    printf("\033[?1049l");
}
