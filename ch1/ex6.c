#include <stdio.h>

main() {
    int c;
    
    for (int i = 0; i < 5; i++) {
        c = (getchar() != EOF);
        printf("%d\n", c);
    }
}

