
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

int char_je_cifra(char c) {
  return '0' <= c && c <= '9';
}

/**
 * vstupny parameter text si mozeme deklarovat ako konstantu, aby
 * sa kompilator nestazoval, ved aj tak nebudeme text menit
 */
int moje_atoi(const char* text) {
  // atoi: premena textu na int
  int hodnota   = 0;
  int znamieko  = 1;  // znamieko pouzijeme na negativne cisla

  // odignoruj biele znaky na zaciatku
  while (*text == ' ' || *text == '\t') {
    text++;
  }

  // skontroluje znamienko
  if (*text == '-') {
    znamieko = -1;
    text++;
  }

  for (int i=0; *text != '\0' && char_je_cifra(*text); i++) {
    hodnota = (hodnota*10) + char_to_int(*text);
    text++;
  }

  return hodnota * znamieko;
}

int main() {
  printf("%d\n", moje_atoi("123") );
  printf("%d\n", moje_atoi("-1") );
  printf("%d\n", moje_atoi("00052") );
  printf("%d\n", moje_atoi("  -005") );
  printf("%d\n", moje_atoi("cdsa4616") );
}