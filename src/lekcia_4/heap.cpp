#include <stdio.h>
#include <stdlib.h>

// definovane v oblasti "static" pocas kompilacie
// int data[100][100];      // data[100*100]
// data[x][y]  -> data[x*100 + y]

/**
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * 0 1 2 3 4 5 6 7 8    // index
 * 1 2 3 4 5 6 7 8 9    // hodnota
 *
 * data[1][1] -> data + 1*3 + 1 -> data + 4
 */

int main(int argc, char* argv[]) {
    int x = std::atoi(argv[1]);
    int y = std::atoi(argv[2]);


    /**
     * Vytvorene v oblasti "heap" po starte programu
     * tabulka
     * 0 -> riadok_0[]
     * 1 -> riadok_1[]
     * 2 -> riadok_2[]
     * ...
     *
     * tabulka[4][3]:
     * *((*(tabulka+4)) + 3) = 5165;
     */
    int** tabulka = (int **) malloc(x * sizeof(int*));
    for (int i=0; i < x; i++) {
        tabulka[i] = (int*) malloc(y * sizeof(int));
    }

    for (int i = 0; i < x; i++) {
        for (int j=0; j<y; j++) {
            printf("(%d, %d) %d\t", i, j, tabulka[i][j]);
        }
        printf("\n");
    }
}