#include <stdio.h>
#include "calc.h"
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
