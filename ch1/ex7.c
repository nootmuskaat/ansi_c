#include <stdio.h>

main() {
    int c;

    while ((c=getchar()) != EOF) {
        putchar(c);
    }
    printf("%d %c\n", c, c);
}
