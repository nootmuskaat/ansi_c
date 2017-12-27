/*  Write a function invert(x,p,n) that returns x 
 *  with the n bits that begin at position p 
 *  inverted (i.e., 1 changed into 0 and vice versa),
 *  leaving the others unchanged.
 */
#include <stdio.h>

int invert(unsigned x, int p, int n);

int main() {
    printf("%d\n", invert(222, 2, 2)); // => 216
    printf("%d\n", invert(555, 5, 5)); // => 533
    printf("%d\n", invert(7777, 7, 7)); // => 7839
    return 0;
}

int invert(unsigned x, int p, int n) {
    unsigned r;
    unsigned m = ~(~0 << n) << (p - n + 1);
    r = m & ~x;
    x &= ~m;
    return (r | x);
}
