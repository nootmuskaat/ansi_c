/* Write a function rightrot(x,n) that
 * returns the value of the integer x rotated 
 * to the right by n bit positions.  
 */
#include <stdio.h>

int rightrot(unsigned x, int n);

int main() {
    int i = 2084143221;
    printf("%10d\n", rightrot(i, 1));
    printf("%10d\n", rightrot(i, 5));
    printf("%10d\n", rightrot(i, 9));
    printf("%10d\n", rightrot(i, 13));
    printf("%10d\n", rightrot(i, 21));
    printf("%10d\n", rightrot(i, 23));
}

int rightrot(unsigned x, int n) {
    if (x == 0)
        return x;
    int i, j;
    int lb, len;
    // calculate bit length of x
    len = 1; 
    for (j = x-(x>>1); j != 01; ++len)
        j >>= 1;
    // rotate n times
    for (i = 0; i < n; ++i) {
        lb = x & ~(~0 << 1); // last bit of x
        x >>= 1;
        x = x | (lb << len);
    }
    return x;
}

