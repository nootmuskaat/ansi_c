#include <stdio.h>

#define MAXLEN 1000

int reverse(char str[], int max);

// Print the text of each line reveresed
int main() {
    int len;
    char line[MAXLEN];
    while ((len=reverse(line, MAXLEN)) > 0)
        printf("%s\n", line);
    return 0;
}

// returns string length
int reverse(char str[], int max) {
    int c, i, j;
    char holder[max];
    for (i=0; i<max-1 && (c=getchar())!='\n' && c!=EOF; ++i)
        holder[i] = c;
    for (j=i; j > 0; --j)
        str[i-j] = holder[j-1];
    if (c == '\n') {
        str[i] == '\n';
        ++i;
    }
    str[i] = '\0';
    return i;
}
