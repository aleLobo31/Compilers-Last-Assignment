#include <stdio.h>

// CEV11.1: Definición de función con parámetros
// CEV11.2: Retorno de valor mediante sentencia return
product (int v, int w) {
    return (v*w) ;
}

// CEV11.4: Función recursiva (Llamada a sí misma)
fact (int n) {
    int f ;
    if (n == 1) {
        f = 1 ;
    } else {
        // CEV11.3: Llamada a función desde otra función (fact llama a fact)
        f = n * fact (n-1) ;
    }
    return f ;
}

is_even (int v) {
    int ep ;
    printf("%d", v) ;
    if (v % 2 == 0) {
        puts (" is even") ;
        ep = 1 ;
    } else {
        puts (" is odd") ;
        ep = 0 ;
    }
    return ep ;
}

main() {
    // CEV11.3: Llamada a funciones externas desde el ámbito main
    printf ("%d\n", product (7, 7)) ;
    puts("");
    printf ("%d\n", fact (7)) ;
    puts("");
    printf ("%d\n", is_even (7)) ;
    puts("");
    printf ("%d\n", is_even (8)) ;
    puts("");
    is_even (8) ;
//     system ("pause") ;
}

//@ (main)
