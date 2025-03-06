#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) == 1 && *n <= NMAX) {
        for (int *p = a; p - a < *n; p++)
            if (scanf("%d", p) != 1 || *p != (int)*p) return 0;
        return 1;
    } else
        return 0;
}

void output(int *a, int n) {
    int i = 0;
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (i < n - 1) {
            printf(" ");
            i++;
        }
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) *p = pow(*p, 2);
}
