#include <stdio.h>

int base = 10;

main() {
    // CEV3.1: Cadena estándar
    puts("INICIO DE PRUEBAS");
    
    // VLV3.1: Cadena vacía (Límite inferior)
    puts("");

    // VLV4.1: Un solo elemento a imprimir (la primera cadena se descarta)
    printf("Ignorado 1", base);

    puts("");

    // CEV4.2: Printf con formato
    printf("%d", base);

    puts(""); 

    // CEV4.1: Múltiples elementos (recursividad, strings y matemáticas)
    printf("Ignorado 2 %s %d %s %d", "El doble de ", base, " es ", base * 2);
    
    puts("");

    puts("FIN");
//     system ("pause") ;
}

//@ (main)
