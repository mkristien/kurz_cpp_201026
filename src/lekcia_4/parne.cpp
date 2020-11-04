#include <stdio.h>
#include "parne.h"

int neparne(int x) {
    if (x == 0) {
        return 0;
    } else {
        return parne(x-1);
    }
}

int parne(int x) {
    if (x == 0) {
        return 1;
    } else {
        return neparne(x-1);
    }
}


// int main() {
//     if (parne(50)) {
//         printf("parne\n");
//     } else {
//         printf("neparne\n");
//     }
// }