#include <stdio.h>

/* Celsius to Fahrenheit conversion */


/*LL not putting variables in a function creates lots of issues */
main() {
    float fahr, cel;
    float start, stop, step;

    start = -40.0;
    stop = 150.0;
    step = 10.0;

    printf("Celsius Fahrenheit\n");
    cel = start;
    while (cel <= stop) {
        fahr = (9.0/5.0) * cel + 32;
        printf("%4.0f %9.1f\n", cel, fahr);
        cel += step;
    }
}
