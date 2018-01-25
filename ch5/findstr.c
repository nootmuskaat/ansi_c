#include <stdio.h>
#include <string.h>
#include "getline.h"

#define MAXLINE 1000

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int c, except, number, found, lineno;
    except = number = found = lineno = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0]))
            switch (c) {
                case 'v':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("findstr: invalid option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
    }
    if (argc != 1)
        printf("usage: findstr -n -v string\n");
    else
        while (getline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%d:", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found;
}
