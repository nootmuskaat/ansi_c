/**
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s
 */

void orig_strcat(char s[], char t[]);
void strcat(char *s, char *t);
int test_strcat(void);

int main() {
    
}

int test_strcat(void) {
    return 0;
}

void strcat(char *s, char *t) {
}

void orig_strcat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0')
        ;
}
