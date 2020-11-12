#include <stdio.h>

int dlzka_textu(char* text) {
  int dlzka = 0;
  while (*text) {
    dlzka++;
    text++;
  }
  return dlzka;
}

void opacne(char* text, char* opacny_text) {
  int dlzka = dlzka_textu(text);
  for (int i=0; i<dlzka; i++) {
    opacny_text[i] = text[dlzka - 1 - i];
  }
}

void opacne_na_mieste(char* text) {
  int dlzka = dlzka_textu(text);
  for (int i=0; i < dlzka/2; i++) {
    char c = text[dlzka - 1 - i];
    text[dlzka - 1 - i] = text[i];
    text[i] = c;
  }
}

int main() {
  char text[] = "abcdefgh";
  char text_opacne[sizeof(text)];

  opacne(text, text_opacne);
  printf("rovno %s a opacne %s\n", text, text_opacne);

  opacne_na_mieste(text);
  printf("originalny text %s\n", text);
}