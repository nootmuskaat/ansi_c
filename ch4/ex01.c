/* Write the function strindex(s,t) , which returns the position of the
 * rightmost occurrence of t in s , or -1 if there is none
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXLINE 1000

int _getline(char line[], int max);
int strindex(char s[], char t[]);

char pattern[] = "ould";

int main() {
    char line[MAXLINE];
    int found = 0;
    // test strindex
    assert(strindex("89898989", "89") == 6);
    assert(strindex("dog dog dog", "dog") == 8);
    assert(strindex("rcat cat cat", "rcat") == 0);
    assert(strindex("horse horse", "HORSE") == -1);

    while (_getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int _getline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// return index of right-most match for string t in string s
int strindex(char s[], char t[]) {
    int i, j, k;
    for (i=strlen(s)-1; i >= 0; --i) {
        for (j=i, k=strlen(t)-1; j>=0 && k>=0 && s[j]==t[k]; --j, --k)
            if (k == 0)
                return j;
    } 
    return -1;
}
