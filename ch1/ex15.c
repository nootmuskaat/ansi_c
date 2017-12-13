#include <stdio.h>

#define MIN 0.0
#define MAX 100.0
#define STEP 10.0

float f_to_c(float fahr);
float c_to_f(float cel);

main() {
    float i;

    for (i = MIN; i <= MAX; i += STEP)
        printf("%3.0f C = %5.1f F\n", i, c_to_f(i));
    printf("\n");
    for (i = MIN; i <= MAX; i += STEP)
        printf("%3.0f F = %5.1f C\n", i, f_to_c(i));
}

float f_to_c(float fahr) {
    return (5.0/9.0)*(fahr-32);
}

float c_to_f(float cel) {
    return (9.0/5.0) * cel + 32;
}
