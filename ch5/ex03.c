/**
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s
 */
#include <assert.h>
#include <string.h>

#define LEN 1000

void new_strcat(char *s, char *t);
int test_strcat(void);

int main() {
    test_strcat();
    return 0;
}

int test_strcat(void) {
    char s[LEN] = "";
    new_strcat(s, "This ");
    new_strcat(s, "is ");
    new_strcat(s, "just ");
    new_strcat(s, "a ");
    new_strcat(s, "test.");
    assert(!strcmp(s, "This is just a test."));
    return 0;
}

void new_strcat(char *s, char *t) {
    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
    return;
}

void orig_strcat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}
