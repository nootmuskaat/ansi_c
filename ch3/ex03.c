/* Write a function expand(s1,s2) that expands shorthand notations like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for
 * letters of either case and digits, and be prepared to handle cases like
 * a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
 * literally. 
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define MAXLINE 1000

void expand(char s1[], char s2[]);

int main() {
    char s[MAXLINE];
    expand("a-i", s);
    assert(!strcmp(s, "abcdefghi"));
    expand("a-cv-z", s);
    assert(!strcmp(s, "abcvwxyz"));
    expand("some m-r thing", s);
    assert(!strcmp(s, "some mnopqr thing"));
    expand("a-b-c", s);
    assert(!strcmp(s, "abc"));
    expand("-a-i", s);
    assert(!strcmp(s, "-abcdefghi"));
    expand("ok -a-i", s);
    assert(!strcmp(s, "ok -abcdefghi"));
    expand("a-dR-Z", s);
    assert(!strcmp(s, "abcdRSTUVWXYZ"));
    expand("a-z0-9", s);
    assert(!strcmp(s, "abcdefghijklmnopqrstuvwxyz0123456789"));
    return 0;
}

void expand(char s1[], char s2[]) {
    int c, i, j;
    for (i=j=0; (c = s1[i]) != '\0'; ++i) {
        /* if a '-' is found between two alphanumeric chars, increment chars 
         * from the left-side char till the right-side char is found */

        if (c == '-' && i > 0 && isalnum(s1[i-1]) && isalnum(s1[i+1])) {
            c = s1[++i];
            while (s2[j-1] != c)
                s2[j++] = s2[j-1] + 1;
        }
        else
            s2[j++] = c;
    }
    s2[j] = '\0';
    return;
}
