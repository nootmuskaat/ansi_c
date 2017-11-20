#include <stdio.h>

/* fahrenheit to celsius conversion */
main() {
    float fahr, cel;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit  Celsius\n");
    while (fahr <= upper) {
        cel = (5.0/9.0) * (fahr-32.0);
        /* LL using %d for a float has hideous results */
        printf("%6.0f %11.1f\n", fahr, cel);
        fahr = fahr + step;
    }
}


