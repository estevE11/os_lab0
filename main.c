#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int random(int max);
int random_from_seed(int seed, int max);
long long current_timestamp();

int main(int argc, char *argv[]) {
    int max = 100;
    if(argc == 2) {
        max = atoi(argv[1]);
    }

    printf("Generating a number from 1 to %d\n\n", max);
    int n = random(max)+1;

    int x;

    for (int i = 0; i < 10; i++) {
        printf("Attempts left: %d\n", 10-i);
        printf("Try to guess the number: \n");
        scanf("%d", &x);
        if (x > n) {
            printf("The correct number is LOWERn\n");
        }
        else if (x < n) {
            printf("The correct number is HIGHER\n\n");
        }
        else {
            printf("The number is CORRECT!\n");
            break;
        }
    }
    return 0;
}

// Problem:
// If we try generating random numbers too fast
// the timestaps doesn't change so the seed is
// the same.
int random(int max) {
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
    gettimeofday(&te, NULL);                                         // get current time
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}