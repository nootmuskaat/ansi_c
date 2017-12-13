#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);
//void _copy(char to[], char from[]);

//Print the length of each line and as much of the line as possible
main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        printf("%3d|%s", len, line);
    }
    return 0;
}

int _getline(char s[], int lim) {
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/*
void _copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
*/
