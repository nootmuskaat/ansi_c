#include <stdio.h>

#define MAXLENGTH 1000
#define ATLEAST 80

int _getline(char line[], int maxlength);

//Print only lines of length 80 chars or longer, such as this line here if I ramble
int main() {
    int len;
    char current[MAXLENGTH];
    while ((len = _getline(current, MAXLENGTH)) > 0) {
        if (len >= ATLEAST)
           printf("%s", current); 
    }
    return 0;
}

int _getline(char line[], int maxlength) {
    int c, i;
    for (i = 0; i<(maxlength-1) && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
