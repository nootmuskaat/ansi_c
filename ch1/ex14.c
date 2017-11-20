#include <stdio.h>

main() {
    int c, i, j;
    int nwhite, nother; 
    int ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;
    }
    printf(" WS: ");
    for (i = 0; i < nwhite; ++i)
        printf("[]");
    printf("\n");
    printf("Oth: ");
    for (i = 0; i < nother; ++i)
        printf("[]");
    printf("\n");
    for (i = 0; i < 10; ++i) {
        printf("%3d: ", i);
        for (j = 0; j < ndigit[i]; ++j)
            printf("[]");
        printf("\n");
    }
}
