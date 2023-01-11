#include <stdio.h>
#include <sys/time.h>

int random(int max);
int random_from_seed(int seed, int max);
long long current_timestamp();

int main(int argc, char *argv[]) {
    printf("hello world\n");

    int rand = random(10);
    
    int x;
    printf("Try to guess the number: \n");
    scanf("%d", &x);
    if(x > rand) {
        printf("The correct number is lower\n");
    } else if (x < rand) {
        printf("The correct number is higher\n");
    } else {
        printf("The number is correct!\n");
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