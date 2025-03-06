#include <stdio.h>

int main() {
    float x, y;
    if (scanf("%f", &x) && scanf("%f", &y)) { /* Чтение 2-х чисел */
        float res = x * x + y * y;
        // printf ("%.4f\n", res);
        if (res <= 25)
            printf("GOTCHA\n");
        else
            printf("MISS\n");
    } else
        printf("n/a\n");
    return 0;
}