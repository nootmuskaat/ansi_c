#include <stdio.h>

#define MAXLINE 1000

void end_of_comment(void);
void end_of_quote(char quote);
void err_message(char found, char closer);

int c;

// Review input file for basic syntax (brackets and quotes)
int main() {
    int i;
    char sym[MAXLINE]; // symbol stack
    extern int c;

    i = 0;
    while ((c=getchar()) != EOF) {
        // pass over comments and things in quotes
        if (c == '/') {
            end_of_comment();
        }
        if (c == '\'' || c == '"')
            end_of_quote(c);
        /* pop open brackets onto stack,
         pop off only if closing bracket found */
        if (c == '{' || c == '[' || c == '(') {
            sym[i] = c;
            ++i;
        }
        else if (c == '}') {
            if (sym[i-1] == '{')
                --i;
            else
                err_message(sym[i-1], c);
        }
        else if (c == ']') {
            if (sym[i-1] == '[')
                --i;
            else
                err_message(sym[i-1], c);
        }
        else if (c == ')') {
            if (sym[i-1] == '(')
                --i;
            else
                err_message(sym[i-1], c);
        }
    }

    if (i > 0)
        printf("Unmatched %c found\n", sym[i-1]);
    return i;
}

void err_message(char found, char closer) {
    printf("Found %c before closing %c\n", found, closer);
    return;
}

// returns when the end of a quote has been found
void end_of_quote(char quote) {
    extern int c;
    while ((c=getchar())!= quote)
        if (c == '\\')
            c = getchar();
    return;

}

// returns when the end of a comment has been found
void end_of_comment(void) {
    extern int c;
    c = getchar();
    if (c == '/') {
        while (c != '\n')
            c = getchar();
    }
    else if (c == '*') {
        c = getchar();
        while (c != EOF) {
            c = getchar();
            if (c == '*') {
                c = getchar();
                if (c == '/');
                    break;
            }
        }
    }
    else
        putchar(c);
    return;
}
