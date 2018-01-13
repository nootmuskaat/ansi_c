/**
 * Write the function strend(s,t) , which returns 1 if the string t occurs at
 * the end of the string s , and zero otherwise.
 **/
#include <assert.h>

int strend(char *s, char *t) {
    //int i, j;
    char *ps = s;
    char *pt = t;
    while (*ps)
        ps++;
    while (*pt)
        pt++;
    while (*pt == *ps && pt >= t && ps >= s) {
        pt--;
        ps--;
    }
    // if the loop exited because all of t was found in s
    if (pt < t)
        return 1;
    else
        return 0;
}

int test_strend(void) { 
    assert(strend("", ""));
    assert(!strend("", " "));
    assert(strend(" ", " "));
    assert(!strend("\n", "\t"));
    assert(strend("ok\n", "\n"));
    assert(strend("walk the dog", "dog"));
    assert(strend("walk the dog", "walk the dog"));
    assert(!strend("walk the dog.", "dog"));
    return 0;
}

int main() {
    test_strend();
    return 0;
}
