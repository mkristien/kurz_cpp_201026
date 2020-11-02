
#include <stdio.h>

/**
 * '0' -> x
 * '1' -> x+1
 * '2' -> x+2
 * '3' -> x+3
 * ...
 *
 *
 * 123, '4'
 * 123*10 -> 1230 + char_to_int('4') -> 1230 + 4 -> 1234
 */

int char_to_int (char c) {
    return c - '0';     // '3' - '0' = (x+3) - x = 3
}

int moje_atoi(char* text) {
    // atoi: premena textu na int
    int hodnota = 0;
    // while (*text != '\0') {
    for (int i=0; text[i] != '\0'; i++) {
        hodnota = (hodnota*10) + char_to_int(text[i]);

        printf("%c %d\n", text[i], hodnota);

        text++;
    }

    return hodnota;
}

int main() {
    printf("%d\n", moje_atoi("12345") );
}