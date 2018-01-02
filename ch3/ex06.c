/* Write a version of itoa that accepts three arguments instead of two.
 * The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough.
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXLINE 1000

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main() {
    char s[MAXLINE];
    char t[] = "Test ING";
    reverse(t);
    assert(strcmp(t, "GNI tseT") == 0);
    itoa(122, s, 5);
    assert(strcmp(s, "  122") == 0);
    itoa(-287, s, 8);
    assert(strcmp(s, "    -287") == 0);
    itoa(-12345, s, 2);
    assert(strcmp(s, "-12345") == 0);
    itoa(1337, s, 4);
    assert(strcmp(s, "1337") == 0);
    return 0; 
}

void reverse(char s[]) {
    int c, i, j;
    for (i=0, j=strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return;
}

void itoa(int n, char s[], int w) {
    assert(w > 0);
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = '0' + (n % 10);
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
    return;
}
