/* Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16)
 * formats n as a hexadecimal integer in s
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXLINE 1000

char numtochar(unsigned n);
void reverse(char s[]);
void itob(int n, char s[], unsigned b);

int main() {
    // test numtochar
    assert(numtochar(1) == '1');
    assert(numtochar(11) == 'b');
    assert(numtochar(61) == 'Z');
    assert(numtochar(62) == '+');
    // test reverse
    char t[] = "TestiNg";
    reverse(t);
    assert(!strcmp(t, "gNitseT"));
    // test itob
    char s[MAXLINE];
    itob(10, s, 10);
    assert(strcmp(s, "10") == 0);
    itob(11, s, 2);
    assert(strcmp(s, "1011") == 0);
    itob(100, s, 8);
    assert(strcmp(s, "144") == 0);
    itob(1337, s, 32);
    assert(strcmp(s, "19p") == 0);
    itob(127, s, 64);
    assert(strcmp(s, "1/") == 0);
    return 0;
}

/* This numbering is not standard base-64, but will be consistent so long
 * as base <= 64
 * 0..63 => 0..9a..zA..Z+/
 */
char numtochar(unsigned n) {
    assert(n < 64);
    if (n < 10)
        return ('0' + n);
    else if (n >= 10 && n < 36)
        return ('a' + (n - 10));
    else if (n >= 36 && n < 62)
        return ('A' + (n - 36));
    else if (n == 62)
        return '+';
    else if (n == 63)
        return '/';
    else
        return '?'; // should never run
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

void itob(int n, char s[], unsigned b) {
    assert(b <= 64);
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = numtochar(n % b);
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    return;
}
