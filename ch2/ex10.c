#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        printf("%c", (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c);
    }
    return 0;
}
