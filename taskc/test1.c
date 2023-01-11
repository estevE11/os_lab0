#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int randomInt(int max);
int random_from_seed(int seed, int max);
long long current_timestamp();
int compared(int a, int b);
int getcenter(int a, int b);

int main(int argc, char *argv[]) {
    int max = 100;
    if(argc == 2) {
        max = atoi(argv[1]);
    }

    printf("Generating a number from 1 to %d\n\n", max);
    int rand = randomInt(max)+1;
    int x = max/2;
    int lo = 0, hi = max+1;

    int found = 0;

    for (int i = 0; i < 10; i++) {
        printf("Current number: %d\n", x);
        if (compared(rand, x) < 0) {
            printf("The correct number is LOWER\n\n");
            hi = x;
            x = getcenter(lo, x);

        }
        else if (compared(rand, x) > 0) {
            printf("The correct number is HIGHER\n\n");
            lo = x;
            x = getcenter(x, hi);
        } else {
            printf("The number is CORRECT!\n");
            found = 1;
            break;
        }
    }
    if(found == 0) printf("\n\nCorrect number not found!! (%d)", rand);
    return 0;
}

// returns 0 if a == b
// returns positive number if a > b
// returns negative number if a < b
int compared(int a, int b) {
    return a - b;
}

int getcenter(int a, int b) {
    return ((b - a) / 2 + a);
}

// Problem:
// If we try generating random numbers too fast
// the timestap does not change so the seed is
// the same.
int randomInt(int max) {
    long long t = current_timestamp();
    int seed = (t - 1673431506680) % 1000;

    int rand = random_from_seed(seed, max);
    return rand;
}

int random_from_seed(int seed, int max) {
    float rand = ((seed*234324 + 432234) % 100) / 100.0f;
    return rand * max;
}

long long current_timestamp()
{
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}