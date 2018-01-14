/**
 * Write versions of the library functions strncpy , strncat , and strncmp ,
 * which operate on at most the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s .
 * Full descriptions are in Appendix B
 **/
#include <assert.h>
#include <string.h>

char *my_strncpy(char *s, const char *t, int n);
char *my_strncat(char *s, const char *t, int n);
int my_strncmp(const char *s, const char *t, int n);

int test_strncpy(void);
int test_strncat(void);
int test_strncmp(void);

int main() {
    test_strncpy();
    test_strncat();
    test_strncmp();
    return 0;
}

char *my_strncpy(char *s, const char *t, int n){
    // does not confirm s has space
    char *ps = s;
    for ( ; n > 0 && (*ps = *t); n--, t++, ps++)
        ;
    return s;
}

char *my_strncat(char *s, const char *t, int n) {
    char *ps = s;
    for ( ; *ps; ps++)
        ;
    for ( ; n > 0 && (*ps = *t); n--, ps++, t++)
        ;
    if (*ps)
        *(++ps) = '\0';
    return s;
}

int my_strncmp(const char *s, const char *t, int n) {
    while (n > 0) {
        if (*s != *t)
            return (*s - *t);
        n--, s++, t++;
    }
    return 0;
}

int test_strncpy(void) {
    char s[] = "TESTING";
    char *ps;
    ps = my_strncpy(s, "HACK", 4);
    assert(!strcmp(ps, "HACKING"));
    ps = my_strncpy(s, "HACK", 6);
    assert(!strcmp(ps, "HACK"));
    return 0;
}

int test_strncat(void) {
    char s[100] = "walk";
    char *ps;
    ps = my_strncat(s, "nonsense", 0);
    assert(!strcmp(s, "walk"));
    ps = my_strncat(s, " the dog, please.", 8);
    assert(!strcmp(ps, "walk the dog"));
    ps = my_strncat(s, ", please!!!", 8);
    assert(!strcmp(ps, "walk the dog, please"));
    return 0;
}

int test_strncmp(void) {
    assert(my_strncmp("DOG", "dog", 3) < 0);
    assert(my_strncmp("dog", "doggy", 3) == 0);
    assert(my_strncmp("doggy", "dog", 4) > 0);
    return 0;
}
