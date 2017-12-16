#include <stdio.h>

#define TABLEN 8
#define MAXLINE 1000

char line[MAXLINE];

int entab(void);

int main() {
    int len;
    extern char line[];
    while ((len = entab()) > 0)
        printf("%s", line);
    return 0;
}

// replace spaces with tabs while maintaining proper offset
int entab(void) {
    int c, i, j, k;
    int lnw; // last non-whitespace char
    extern char line[];

    i = j = 0;
    lnw = -1;
    while (i<MAXLINE-1 && (c=getchar())!='\n' && c!=EOF) {
        if (c == '\t')
            j = TABLEN - 1;
        else if (c != ' ') {
            // fill in missing spaces as needed
            for (k = 0; k < j-(lnw+1); ++k) {
                line[i] = ' ';
                ++i;
            }
            lnw = j;
            line[i] = c;
            ++i;
        }
        if (j == TABLEN - 1 && lnw != j) {
            lnw = -1;
            line[i] = '\t';
            ++i;
        }
        j = ++j % TABLEN;
        if (j == 0)
            lnw = -1;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
