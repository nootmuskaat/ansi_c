/**
 * Write the program expr, which evaluates a reverse Polish expression from
 * the command line, where each operator or operand is a separate argument.
 * For example, "expr 2 3 4 + *" evaluates "2 x (3 + 4)"
 **/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const int maxstack = 100;

int main(int argc, char *argv[]) {
    int stack[maxstack];
    int *stackp = stack;

    while (--argc > 0 && (*++argv)) {
        switch (*argv[0]) {
            case '+':
                if (stackp - stack >= 2) {
                    *(stackp-2) = *(stackp-1) + *(stackp-2);
                    stackp--;
                }
                break;
            case '-':
                if (stackp - stack >= 2) {
                    *(stackp-2) = *(stackp-2) - *(stackp-1);
                    stackp--;
                }
                break;
            case '*':
                if (stackp - stack >= 2) {
                    *(stackp-2) = *(stackp-1) * *(stackp-2);
                    stackp--;
                }
                break;
            case '/':
                if (stackp - stack >= 2) {
                    *(stackp-2) = *(stackp-2) / *(stackp-1);
                    stackp--;
                }
                break;
            default:
                if (!isdigit(*argv[0])) {
                    printf("invalid argument '%s'\n", *argv);
                    return -1;
                }
                *stackp++ = atoi(*argv);
                break;
        }
    }
    printf("%d\n", *stack);
    return *stack;
}

