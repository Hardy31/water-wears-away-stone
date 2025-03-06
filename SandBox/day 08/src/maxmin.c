#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Find a max & min probabilities */
int main() {
    float x, y, z;
    int a, b, c;

    if (scanf("%f %f %f", &x, &y, &z) == 3) {
        a = (int)x;
        b = (int)y;
        c = (int)z;
        if (x == a && y == b && z == c) {
            int max, min;
            maxmin(a, b, c, &max, &min);
            printf("%d %d", max, min);
        } else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}

/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    *max = *min = prob1;

    if (prob2 > *max) *max = prob2;
    if (prob2 < *min) *min = prob2;

    if (prob3 > *max) *max = prob3;
    if (prob3 < *min) *min = prob3;
}
