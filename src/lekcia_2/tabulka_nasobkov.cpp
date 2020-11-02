
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Prosim, zadaj dve cisla ako hranice naboskovej tabulky\n"
               "pouzitie:\n"
               "%s <riadky> <stlpce>\n",
               argv[0]
        );
        return 1;
    }

    int riadky = std::atoi(argv[1]);
    int stlpce = std::atoi(argv[2]);

    for (int i = 1; i <= riadky; i++) {
        for (int j = 1; j <= stlpce; j++) {
            printf("%d * %d = %d\t", i, j, i * j);
        }
        printf("\n");
    }
}

