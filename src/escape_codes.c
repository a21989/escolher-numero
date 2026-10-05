#include <stdio.h>

// https://en.wikipedia.org/wiki/ANSI_escape_code
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
// https://rosettacode.org/wiki/Terminal_control/Preserve_screen

int disable_buffer() {
    return setvbuf(stdout, NULL, _IONBF, 0);
}

int enable_line_buffer() {
    return setvbuf(stdout, NULL, _IOLBF, 32);
}

void clear_screen_and_move_cursor_to_start() {
    printf("\x1B[2J\x1B[H");
}

void enter_alternate_screen() {
    printf("\x1B[?1049h");
}

void leave_alternate_screen() {
    printf("\x1B[?1049l");
}
