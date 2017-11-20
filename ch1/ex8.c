#include <stdio.h>

main() {
    int c;
    long spaces = 0;
    long tabs = 0;
    long newlines = 0;

    while ((c=getchar()) != EOF) {
        if (c == ' ')
            ++spaces;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;
    }
    printf("Spaces:    %ld\n", spaces);
    printf("Tabs:      %ld\n", tabs);
    printf("New Lines: %ld\n", newlines);
}
