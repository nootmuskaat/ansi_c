/**
 * Write the function strend(s,t) , which returns 1 if the string t occurs at
 * the end of the string s , and zero otherwise.
 **/
#include <assert.h>
#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);
int test_strend(void);

int main() {
    test_strend();
    return 0;
}

int test_strend(void) { 
    assert(strend("", ""));
    assert(!strend("", " "));
    assert(strend(" ", " "));
    assert(!strend("\n", "\t"));
    assert(strend("ok\n", "\n"));
    assert(strend("walk the dog", "dog"));
    assert(!strend("walk the dog.", "dog"));
    return 0;
}

int strend(char *s, char *t) {
    return 0;
}



