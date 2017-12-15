#include <stdio.h>

#define MAXLINE 1000

int max; // largest known length
char line[MAXLINE]; // current line of input
char longest[MAXLINE]; // longest line

int _getline(void);
void _copy(void);

// print the longest line from the input
int main() {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = _getline()) > 0) {
        if (len > max) {
            max = len;
            _copy();
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int _getline(void) {
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF 
            && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void _copy(void) {
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i]=line[i]) != '\0')
        ++i;
}
