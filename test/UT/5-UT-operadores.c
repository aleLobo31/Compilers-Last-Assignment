#include <stdio.h>

int a = 10, b = 5;

main() {
    int r;
    
    // CEV5.1 (&&) y CEV5.2 (||)
    r = (a > 0) && (b < 10);
    printf("%d", r);
    r = (a == 0) || (b == 5);
    printf("%d", r);
    
    // CEV5.3 (!=) y CEV5.4 (==)
    r = a != b;
    printf("%d", r);
    r = a == 10;
    printf("%d", r);
    
    // CEV5.5 (<) y CEV5.6 (>)
    r = a < b;
    printf("%d", r);
    r = a > b;
    printf("%d", r);
    
    // CEV5.7 (<=) y CEV5.8 (>=)
    r = a <= 10;
    printf("%d", r);
    r = b >= 5;
    printf("%d", r);
    
    // CEV5.9 (%)
    r = a % b;
    printf("%d", r);
//     system ("pause") ;
}

//@ (main)
