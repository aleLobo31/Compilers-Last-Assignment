#include <stdio.h>

int x = 10;

main() {
    // CEV7.1 (Sin Else) y CEV7.4 (Sentencia Simple)
    if (x == 10) {
        puts("X es 10");
    }

    // CEV7.2 (Con Else) y CEV7.5 (Multiples Sentencias)
    if (x > 5) {
        puts("Es mayor");
        x = x - 1;
    } else {
        puts("Es menor o igual");
        x = x + 1;
    }

    // CEV7.3 (Condicional Múltiple / Dangling Else)
    if (x != 0) {
        if (x == 9) {
            puts("Anidado correcto");
        }
    } else {
        puts("Este else pertenece al primer IF gracias a las llaves");
    }
//     system ("pause") ;
}

//@ (main)
