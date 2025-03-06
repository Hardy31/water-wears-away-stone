#include <stdio.h>

float searchmax(float x, float y) {  // функция поиска максимума
    if (x > y) {
        return x;
    } else {
        return y;
    } /* Возврат максимального числа */
}

int main() {
    float x, y;
    if (scanf("%f", &x) && scanf("%f", &y)) { /* Чтение 2-х чисел */
        if ((x == (int)x) && y == (int)y)     /* Проверка на целочисленность */
        {
            printf("%.0f\n", searchmax(x, y));
        } else
            printf("n/a\n");
    } else
        printf("n/a\n");
    return 0;
}