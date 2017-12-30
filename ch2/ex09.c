/* In a two's complement number system,
 * x &= (x-1) deletes the rightmost 1-bit in x.
 * Explain why. Use this observation to write
 * a faster version of bitcount . 
 */
#include <stdio.h>

int bitcount(unsigned x);

int main() {
    printf("%4d\n", bitcount(7));
    printf("%4d\n", bitcount(123));
    printf("%4d\n", bitcount(4848484));
    printf("%4d\n", bitcount(2115813434));
}

/* x & (x-1) removes the right-most 1-bit by flipping it to a 0-bit
 * and flipping all trailing 0-bits to 1-bits. The product of the AND
 * operation (x') is therefore x with the right-most 1-bit zeroed.
 * example:
 *   1111110000111001100000000000000 2115813376 (x)
 * & 1111110000111001011111111111111 2115813375 (x-1)
 * = 1111110000111001000000000000000 2115796992
 */

/* count the 1 bits in number x */
int bitcount(unsigned x) {
    int i;
    for (i = 0; x != 0; ++i)
        x &= (x-1);
    return i;
}


/* original
int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
    
} */


