#include <stdio.h>

// CEV12.1: Declaración de vector global
int a[3];

main() {
    // CEV12.2: Declaración de vector b
    int b[2];
    
    // CEV12.3: Asignación a posición de vector (Rol de Receptor)
    a[0] = 55;
    b[1] = 99;
    
    // CEV12.4: Acceso a posición de vector (Rol de Operando)
    printf("a pos 0: %d", a[0]);
    puts("");
    printf("b pos 1: %d", b[1]);
//     system ("pause") ;
}

//@ (main)
