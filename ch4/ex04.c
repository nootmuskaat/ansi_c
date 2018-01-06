/**
 * Add commands to print the top element of the stack without popping,
 * to duplicate the top element, and to swap the top two elements. 
 * Add a command to clear the stack.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void ptop(void);
void duptop(void);
void swaptop(void);
void clrstk(void);

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: cannot divide by zero");
            break;
        case '%':
            op2 = (int) pop();
            if (op2 != 0.0)
                push((int) pop() % (int) op2);
            else
                printf("error: cannot divide by zero");
            break;
        case '\n':
            printf("%.8g\n", pop());
            break;
        default:
            printf("error: unknown command '%s'\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full - can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// print element on top of stack
void ptop(void) {
    if (sp > 0)
        printf("Top of stack: %.8g\n", val[sp-1]);
    else
        printf("error: stack empty\n");
}

// duplicate the top element on the stack
void duptop(void) {
    double top;
    if (sp <= 0)
        printf("error: stack empty\n");
    else {
        top = pop();
        push(top);
        push(top);
    }
    return;
}

// swap the top two elements on the stack
void swaptop(void) {
    double top1, top2;
    if (sp <= 1)
        printf("error: two few items on stack");
    else {
        top1 = pop();
        top2 = pop();
        push(top1);
        push(top2);
    }
    return;
}

// clear stack
void clrstk(void) {
    sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c, tmp;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        ptop();
        return c;
    }
    if (c == '-' && (isspace(tmp = getch()))) {
        ungetch(tmp);
        return c;
    }
    else if (c == '-') {
        c = tmp;
        i = 1;
        s[i] = c;
    }
    else
        i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
