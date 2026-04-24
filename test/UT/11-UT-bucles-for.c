#include <stdio.h>

#define INC(x) x=x+1
#define DEC(x) x=x-1

int i, j, x, y;

main() {
    // CEV9.1: Bucle For con Incremento
    for (i = 0; i < 3; INC(i)) {
        printf("Inc: %d\n", i);
    }

    // CEV9.2: Bucle For con Decremento
    for (j = 2; j >= 0; DEC(j)) {
        printf("Dec: %d\n", j);
    }

    // CEV9.3: Bucle For Anidado
    for (x = 0; x < 2; INC(x)) {
        for (y = 0; y < 2; INC(y)) {
            printf("Coord: %d %d\n", x, y);
        }
    }
//     system ("pause") ;
}

//@ (main)
