#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void descape(char s[], char t[]);

int main() {
    // test functionality
    char s[MAXLINE], t[MAXLINE];
    printf("Escaping:\n");
    escape(s, "\ttesting\n\ntwo lines down\n");
    printf("%s\n", s);
    printf("Un-escaping:\n");
    descape(t, s);
    printf("%s\n", t);
}

void descape(char s[], char t[]) {
    int c, i, j;
    i = j = 0;
    while ((c = t[i]) != '\0') {
        switch (c) {
            case '\\':
                c = t[++i];
                switch (c) {
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j++] = c;
                }
                break;
            default:
                s[j++] = c;
        }
        i++;
    }
    s[j] = '\0';
    return;
}

void escape(char s[], char t[]) {
    int c, i, j;
    i = j = 0;
    while ((c = t[i]) != '\0') {
        switch (c) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = c;
        }
        i++;
    }
    s[j] = '\0';
    return;
}
