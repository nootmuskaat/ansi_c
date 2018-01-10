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
}
