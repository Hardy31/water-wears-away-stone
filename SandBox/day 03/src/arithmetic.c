#include <stdio.h>

int main() {
    float x, y;

    if (scanf("%f", &x) && scanf("%f", &y)) {
        int incr = x + y;
        int decr = x - y;
        int proiz = x * y;
        if (x == (int)x && y == (int)y) {  //проверка на ввод целых чисел
            if (y != 0) {
                int del = x / y;
                printf("%d %d %d %d\n", incr, decr, proiz, del);
            } else {
                printf("%d %d %d n/a\n", incr, decr, proiz);
            }
        } else {
            printf("n/a\n");
        }
    } else
        printf("n/a\n");

    return 0;
}
