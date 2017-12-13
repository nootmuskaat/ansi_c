#include <stdio.h>

#define MAXLEN 1000

int truelen(char str[], int max);

// Remove all trailing whitespace and empty lines
int main() {
    int len;
    char line[MAXLEN]; 
    while (len >= 0) {
        len = truelen(line, MAXLEN);
        printf("%s", line);
    }
}

// Return length of line without trailing whitespace
int truelen(char str[], int max) {
    int idx, c;
    // load the line into the buffer
    for (idx=0; idx<max-1 && (c=getchar())!='\n' && c!=EOF; ++idx)
        str[idx] = c;
    // back track to last non-whitespace
    while (idx > 0 && (str[idx-1] == ' ' || str[idx-1] == '\t'))
        --idx;
    // only add newline if string is not empty
    if (c == '\n' && idx > 0) {
        str[idx] = c;
        ++idx;
    }
    str[idx] = '\0';
    if (c == EOF)
        idx = -1;
    return idx;
}
