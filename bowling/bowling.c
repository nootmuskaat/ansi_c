#include "bowling.h"
#include <stdio.h>

static short score[10][3]; // a frame's score is made up of at most 3 roles
static short frame = 0;
static short roll = 0;


// begin game by zeroing out all frames
void bowl_init() {
    int i, j;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 3; j++)
            score[i][j] = 0;
    frame = roll = 0;
    return;
}

// return -1 if game is complete
int bowl_roll(int n) {
    static short *p1 = NULL;
    static short *p2 = NULL;

    if (frame < 10)
        score[frame][roll] = n;
    if (p1) {
        *p1 = n;
        p1 = NULL;
    }
    if (p2) {
        *p2 = n;
        p1 = p2 + 1;
        p2 = NULL;
    }

    if (roll == 0) {
        if (n == 10 && frame < 10) {
            p2 = &score[frame][1];
            frame++;
        }
        else
            roll++;
    }
    else {
        if (score[frame][1]+score[frame][0]==10)
            p1 = &score[frame][2];
        frame++;
        roll = 0;
    }

    if (frame >= 10 && !p1 && !p2)
        return -1;
    return 0;
}

int bowl_score(void) {
    int i, j;
    int n = 0;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 3; j++)
            n += score[i][j];
    return n;
}

static void print_frame(short f[]);
static void print_frame10(short f[]);

void print_score(void) {
    int fr, total;

    // individual throws
    for (fr = 0; fr < 9; fr++) {
        print_frame(score[fr]);
    }
    print_frame10(score[fr]);
    printf("\n");

    // frame totals
    total = 0;
    for (fr = 0; fr < 10; fr++) {
        total += (score[fr][0] + score[fr][1] + score[fr][2]);
        printf("%4d ", total);
    }
    printf("\n");

    return;
}



static void print_frame(short f[]) {
        if (f[0] == 10)
            printf(" [X] ");
        else if (f[0] + f[1] == 10)
            printf("%c[/] ",
                    (f[0] == 0) ? '-' : '0'+f[0]);
        else
            printf("%c[%c] ",
                    (f[0] == 0) ? '-' : '0'+f[0],
                    (f[1] == 0) ? '-' : '0'+f[1]);
}

static void print_frame10(short f[]) {
        if (f[0] == 10)
            printf("X[%c][%c]",
                    (f[1] == 10) ? 'X' : (f[1] == 0) ? '-' : '0'+f[1],
                    (f[2] == 10) ? 'X' : (f[2] == 0) ? '-' : '0'+f[2]);
        else if (f[0] + f[1] == 10)
            printf("%c[/][%c]",
                    (f[0] == 0) ? '-' : '0'+f[0],
                    (f[2] == 10) ? 'X' : (f[2] == 0) ? '-' : '0'+f[2]);
        else
            printf("%c[%c][ ]",
                    (f[0] == 0) ? '-' : '0'+f[0],
                    (f[1] == 0) ? '-' : '0'+f[1]);
}
