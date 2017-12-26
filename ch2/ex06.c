/* Write a function setbits(x,p,n,y) 
 * that returns x with the n bits that begin at position p
 * set to the rightmost n bits of y,
 * leaving the other bits unchanged. 
 * eg
 * x = 0101010101
 * y = 0111111111
 * p = 4, n = 3
 * => 0101011101
 *         ^^^
*/
#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);

int main() {
    // 10|11|0, 011|01 => 10010 (21)
    printf("%d\n", setbits(22, 2, 2, 13));
    // 11000|00111|0, |10110 => 11000101100 (1580)
    printf("%d\n", setbits(1550, 5, 5, 22));
    // 1010|11001|000, 101|10001 => (2696)
    printf("%d\n", setbits(2760, 7, 5, 177));
    // 10011|1000|10000, ...|1111 => 10011111110000 (10224)
    printf("%d\n", setbits(10000, 8, 4, ~0));
}

int setbits(unsigned x, int p, int n, unsigned y) {
    x &= ~(~(~0 << n) << (p - n + 1)); // zero out bits p through p-n+1
    y &= ~(~0 << n); // reduce y to the n rightmost bits
    y <<= p - n + 1; // shift y over to position p

    return (x | y);
}
