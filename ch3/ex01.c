/* Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests
 * outside). Write a version with only one test inside
 * the loop and measure the difference in run-time. 
 */
#include <stdio.h>

int binsearch(int x, int v[], int len);
int binsearch2(int x, int v[], int len);

int main() {
    // build test array
    int i, j;
    int len = 15;
    int v[len];
    j = 1;
    for (i = 0; i < len; ++i) {
        v[i] = j;
        j += (i + j);
    }
    /* {1,2,5,12,27,58,121,248,503,1014,2037,4084,8179,16370,32753} */
    // test functioning
    j = 2;
    printf("%5d\t%2d\n", j, binsearch2(j, v, len));
    j = 27;
    printf("%5d\t%2d\n", j, binsearch2(j, v, len));
    j = 55;
    printf("%5d\t%2d\n", j, binsearch2(j, v, len));
    j = 4084;
    printf("%5d\t%2d\n", j, binsearch2(j, v, len));
    j = 8178;
    printf("%5d\t%2d\n", j, binsearch2(j, v, len));
    j = 32753;
    printf("%5d\t%2d\n", j, binsearch2(j, v, len));
    return 0;
}

/* as written in the example
 * binsearch 1 results (10,000 iterations)
 * real    0m16.434s
 * user    0m9.359s
 * sys     0m7.601s
 */
int binsearch(int x, int v[], int len) {
    int low, mid, high;
    low = 0;
    high = len - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1; /* x not found in v[] */
}

/* binsearch 2 results (10,000 iterations)
 * real    0m16.489s
 * user    0m9.404s
 * sys     0m7.525s
 */
int binsearch2(int x, int v[], int len) {
    int low, high;
    low = 0;
    high = len - 1;
    while (low <= high) {
        if (x != v[low])
            low++;
        else
            return low;
    }
    return -1;
}

