#include "bowling.h"

#include <assert.h>

void test_all_gutter() {
    bowl_init();
    while (bowl_roll(0) == 0)
        ;
    assert(bowl_score() == 0 && "test_all_gutter()");
    print_score();
}

void test_one_pin() {
    bowl_init();
    while (bowl_roll(1) == 0)
        ;
    assert(bowl_score() == 20 && "test_one_pin()");
    print_score();
}

void test_all_spares() {
    bowl_init();
    while (bowl_roll(5) == 0)
        ;
    assert(bowl_score() == 150 && "test_all_spares()");
    print_score();
}

void test_all_strikes() {
    bowl_init();
    while (bowl_roll(10) == 0)
        ;
    assert(bowl_score() == 300 && "test_all_strikes()");
    print_score();
}

int main() {
    test_all_gutter();
    test_one_pin();
    test_all_spares();
    test_all_strikes();
    return 0;
}
