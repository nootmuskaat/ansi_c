/*
 * ch4/ex11: Modify getop so that it doesn't need to use ungetch.
 * Hint: use an internal static variable
 */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "calc.h"

#define MAXOP 100

int getch(void);

int getop(char s[]) {
    int i, c, tmp;
    static int buf[MAXOP];
    static int bufp = 0;
    // find first non-whitespace
    while ((s[0] = c = (bufp > 0) ? buf[--bufp] : getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    // return operators (exc '-')
    if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-') {
        //ptop();
        return c;
    }
    // asses if '-' is a negative number or minus
    if (c == '-' && (isspace(tmp = (bufp > 0)?buf[--bufp]:getch()))) {
        buf[bufp++] = tmp;
        return c;
    }
    else if (c == '-') {
        c = tmp;
        i = 1;
        s[i] = c;
    }
    else
        i = 0;
    // extended math functions
    if (isalpha(c)) {
        while (!isspace(s[++i] = c = (bufp > 0)?buf[--bufp]:getch()))
            ;
        buf[bufp++] = c;
        s[i] = '\0';
        if (!strcmp(s, "atan2") || !strcmp(s, "pow") || !strcmp(s, "fmod"))
            return MATH_2;
        else
            return MATH_1;
    }
    // numbers
    if (isdigit(c))
        while (isdigit(s[++i] = c = (bufp > 0)?buf[--bufp]:getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = (bufp > 0)?buf[--bufp]:getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        buf[bufp++] = c;
    return NUMBER;
}

// This could probably be written with some type of eval statment
// if I knew how
double math1(char s[], double x) {
    if (!strcmp(s, "sin"))
        return sin(x);
    else if (!strcmp(s, "cos"))
        return cos(x);
    else if (!strcmp(s, "tan"))
        return tan(x);
    else if (!strcmp(s, "asin"))
        return asin(x);
    else if (!strcmp(s, "acos"))
        return acos(x);
    else if (!strcmp(s, "atan"))
        return atan(x);
    else if (!strcmp(s, "exp"))
        return exp(x);
    else if (!strcmp(s, "log"))
        return log(x);
    else if (!strcmp(s, "log10"))
        return log10(x);
    else if (!strcmp(s, "sqrt"))
        return sqrt(x);
    else {
        printf("error: unknown function '%s'", s);
        return 0.0;
    }
}

double math2(char s[], double x, double y) {
    if (!strcmp(s, "atan2"))
        return atan2(x, y);
    else if (!strcmp(s, "pow"))
        return pow(x, y);
    else if (!strcmp(s, "fmod"))
        return fmod(x, y);
    else {
        printf("error: unknown function '%s'", s);
        return 0.0;
    }
}
