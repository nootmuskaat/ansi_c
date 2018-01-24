/**
 * Write a version of function readlines, which doesn't call alloc(), but saves
 * lines to an array provided by main(). How much faster is it?
 **/
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines, char *allocbuf);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main() {
    int nlines;
    char allocbuf[ALLOCSIZE];

    if ((nlines = readlines(lineptr, MAXLINES, allocbuf)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("error: input too large to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int getline(char *, int);

int readlines(char *lineptr[], int maxlines, char *allocbuf) {
    int len, nlines;
    char line[MAXLEN], *p = allocbuf;
    const char *allocmax = allocbuf + ALLOCSIZE;
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p + len > allocmax)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
    return;
}

int getline(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c!='\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}


void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left+right)/2); // put middle element as item 0
    last = left; // last swapped item
    for (i = left+1; i <= right; i++) // starting from element 1 to element n
        if (strcmp(v[i], v[left]) < 0) // if current element is < pivot, swap
            swap(v, ++last, i); // 
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
