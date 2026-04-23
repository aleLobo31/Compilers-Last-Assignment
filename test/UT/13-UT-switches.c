#include <stdio.h>

int opcion1 = 1, opcion2 = 2, vacio = 0;

main() {
    // CEV10.1: Switch con un Caso (Caso base)
    switch(opcion1) {
        case 1: 
            puts("Has elegido 1"); 
            break;
    }

    // CEV10.2 (Múltiples Casos)
    switch(opcion2) {
        case 1:
            puts("Iniciando partida");
            break;
        case 2:
            puts("Cargando partida");
            break;
        default:
            puts("Opcion no valida");
            break;
    }

    // CEV10.3 (Con Default)
    switch(vacio) {
        case 1:
            puts("Iniciando partida");
            break;
        case 2:
            puts("Cargando partida");
            break;
        default:
            puts("Opcion no valida");
            break;
    }
//     system ("pause") ;
}

//@ (main)
