#include <stdio.h>

int a = 0, b = 2, c;

main() {
    // CEV6.1: Bucle While con Sentencia Simple
    puts("Bucle Simple");
    while (a < 3) {
        a = a + 1;
    }
    printf("%d\n", a);

    // CEV6.2: Bucle While Anidado
    puts("Bucle Anidado");
    while (b > 0) {
        c = 0;
        
        while (c < 2) {
            printf("%d", c);
            c = c + 1;
        }
        b = b - 1;
    }
    printf("%d\n", b);
//     system ("pause") ;
}

//@ (main)
