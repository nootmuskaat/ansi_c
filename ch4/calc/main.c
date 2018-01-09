/**
 * Add commands to print the top element of the stack without popping,
 * to duplicate the top element, and to swap the top two elements. 
 * Add a command to clear the stack.
 **/
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case MATH_1:
            push(math1(s, pop()));
            break;
        case MATH_2:
            op2 = pop();
            push(math2(s, pop(), op2));
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
