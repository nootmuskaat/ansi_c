#include <stdio.h>


// program to test the sizes of char, short, int, and long
int main() { 
    signed char c, C;
    signed short s, S;
    signed int i, I;
    signed long l, L;
    c = s = i = l = 0;
    C = S = I = L = 2;
    while (c < C) {
        c = C;
        C *= 2;
    }
    C = c + (c - 1);
    while (c < C)
        c = C++;
    printf("Max signed char:  %18d\n", c);
    while (s < S) {
        s = S;
        S *= 2;
    }
    S = s + (s - 1);
    while (s < s)
        s = S++;
    printf("Max signed short: %18d\n", s);
    while (i < I) {
        i = I;
        I *= 2;
    }
    I = i + (i - 1);
    while (i < I)
        i = I++;
    printf("Max signed int:   %18ld\n", i);
    while (l < L) {
        l = L;
        L *= 2;
    }
    L = l + (l - 1);
    while (l < L)
        l = L++;
    printf("Max signed long: %18ld\n", l);
    return 0;
}

