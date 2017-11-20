#include <stdio.h>

#define IN 0
#define OUT 1

#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'

main() {
    int nw, nl, nc; /* number of words, lines, and chars */
    int c, state;

    nw = nl = nc = 0;
    state = OUT;
    
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == NEWLINE)
            ++nl;
        if (c == SPACE || c == TAB || c == NEWLINE) {
            if (state == IN)
                putchar('\n');
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
            printf("(word count: %4d) ", nw);
        } 
        if (state == IN)
            putchar(c);
    }
    /*
    printf("Words: %d\n", nw);
    printf("Chars: %d\n", nc);
    printf("Lines: %d\n", nl);
    */
}
