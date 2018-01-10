/**
 * Write a recursive version of the function reverse(s) 
 * which reverses the string s in place. 
 **/
#include <assert.h>
#include <string.h>

void reverse(char []);

int main() {
    char s[] = "This is a test string";
    reverse(s);
    assert(!strcmp(s, "gnirts tset a si sihT"));
    reverse(s);
    assert(!strcmp(s, "This is a test string"));
    return 0;
}


void reverse(char s[]) {
    int i, len=strlen(s)-1;
    if (len <= 0)
        return;

    char c, t[len];
    // swap first and last char, reverse middle
    c = s[0], s[0] = s[len], s[len] = c;
    for (i = 0; i < len-1; i++)
        t[i] = s[i+1];
    t[i] = '\0';
    reverse(t);
    for (i = 0; i < len-1; i++)
        s[i+1] = t[i];
    return;
}
