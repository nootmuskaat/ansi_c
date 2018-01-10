/**
 * Define a macro swap(t,x,y) that interchanges two arguments of type t.
 * (Block structure will help.) 
 */
#include <stdio.h>
#include <assert.h>

#define swap(t, x, y) {t z; z = x; x = y; y = z;}

int main() {
    int i = 5;
    int j = 3;
    swap(int, i, j);
    assert(j == 5);
    assert(i == 3);
    return 0;
}
