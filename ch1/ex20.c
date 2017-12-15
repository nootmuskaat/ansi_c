#include <stdio.h>

#define MAXLINE 1000
#define TABLEN 8

char line[MAXLINE];

int detab(void);

int main() {
    int len;
    extern char line[];
    while ((len = detab()) > 0)
       printf("%s", line);
    return 0;
}

int detab(void) {
    int c, i, j;
    extern char line[];
    for (i=0; i<MAXLINE-1 && ((c=getchar())!='\n') && c!=EOF; ++i) {
        // in case of tab, add appropriate number of spaces to offset
        if (c == '\t') {
            for (j=i%TABLEN; j<TABLEN; ++j) {
                line[i] = ' ';
                ++i;
            }
            --i;
        }
        else
            line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
