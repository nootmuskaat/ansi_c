#include <stdio.h>

#define IN 0
#define OUT 1
#define MAX 15

main() {
    int c, i, state, len;
    int wlength[MAX];
    int height;
    height = 0; /* how tall the histogram should be */
    state = OUT;
    for (i = 0; i < MAX; ++i)
        wlength[i] = 0;
    /* Count occurences of each word length, up to MAX */
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
    /* Generate vertical histogram */
    for (i = 0; i < MAX; ++i) {
        if (wlength[i] > height)
            height = wlength[i];
    }
    for (len = height; len > 0; --len) {
        printf(" ");
        for (i = 0; i < MAX; ++i) {
            if (wlength[i] >= len)
                printf("[ ]");
            else
                printf("   ");
        }
        printf("\n");
    }
    for (i = 0; i < MAX; ++i)
        printf("%3d", i+1);
    printf("+\n");
}
