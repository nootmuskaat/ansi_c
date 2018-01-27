/***
 * Write the program tail, which prints the last n lines of its input. By
 * default, n is 10, say, but it can be changed by an optional argument, so that
 * $ tail -n
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n. Write the program so it makes the
 * best use of available storage; lines should be stored as in the sorting
 * program of Section 5.6, not in a two-dimensional array of fixed size. 
 ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getline.h"

const int maxline = 200;
const int defaultlen = 10;
const int expected_args = 2;

int main(int argc, char *argv[]) {
    if (argc > expected_args) {
        printf("usage: %s -n\n", *argv);
        printf("where n is the number of lines\n");
        return 1;
    }
    int tlen = (*++argv) ? atoi(++(*argv)) : defaultlen;
    /* in adhering to K&R, malloc has not yet been presented, so this solution
     * meets buffer size requirements without knowing how big input is */
    const int bufsize = (tlen + 1) * maxline;
    
    int llen, nolines;
    char *tail[tlen], tailbuf[bufsize], line[maxline];
    char *bufp = tailbuf;
    int taili = 0;
   
    while ((llen = getline(line, maxline)) > 0) {
        nolines++;
        if (bufp - tailbuf + llen > bufsize)
            bufp = tailbuf;
        strcpy(bufp, line);
        tail[taili] = bufp;
        bufp += llen+1;
        taili = (taili + 1 < tlen) ? taili+1 : 0;
    }

    if (nolines > tlen) {
        nolines = tlen;
        while (nolines-- > 0) {
            printf("%s", tail[taili]);
            taili = (taili + 1 < tlen) ? taili+1 : 0;
        }
    }
    else {
        while (nolines-- > 0) {
            printf("%s", tail[taili]);
        }
    }

    return 0;
}
