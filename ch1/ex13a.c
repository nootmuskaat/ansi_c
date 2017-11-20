#include <stdio.h>

#define IN 0
#define OUT 1
#define MAX 15

main() {
    int c, i, state, len;
    int wlength[MAX];
    state = OUT;
    for (i = 0; i < MAX; ++i)
        wlength[i] = 0;
    /* count occurences of word lengths, up to MAX */
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (len >= MAX)
                    len = MAX-1;
                ++wlength[len];
            }
            state = OUT;
        }
        else if (state == OUT) {
            len = 0;
            state = IN;
        }
        else
            ++len;
    }
    /* Format horizontal histogram */
    for (i = 0; i < MAX; ++i) {
        if (i == MAX-1)
            printf("%2d+: ", MAX);
        else
            printf("%2d : ", i+1);
        for (int j = 0; j < wlength[i]; ++j)
            printf("[ ]");
        printf("\n");

    }

}
