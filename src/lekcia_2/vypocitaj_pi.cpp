#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int pocet_bodov   = std::atoi(argv[1]);
    int pocet_v_kruhu = 0;

    for (int i=0; i<pocet_bodov; i++) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;

        if (x*x + y*y < 1) {
            pocet_v_kruhu++;
        }
    }

    printf("odhad pi je %f\n", 4.0*pocet_v_kruhu/pocet_bodov);
}
