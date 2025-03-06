#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
//void output(int *a, int n);
//void squaring(int *a, int n);

int main() {
    int n, data[NMAX]; // инициализация
    input(data, &n);
    //printf("%d\n", n);
    //for (int i=0; i<n; i++) printf("%d ", data[i]); printf("\n");
    //squaring(data, n);
    //output(data, n);

    return 0;
}

int input(int *a, int *n) { 
    scanf("%d", &*n); // читаем количество заполняемых ячеек
    printf("Заполняем %d ячеек\n", *n);
    int p, start = a;
    //for (int p = a; *p - *a < *n; p++) {
    for (int x=1; x<=*n;x++) {
        scanf("%d", &p);
        *a = p;
        printf("EL[%d] = %d [%p]\n", x, p, a);
        printf("%d \n", a-start);
        a++;
    }
}
/*
void output(int *a, int n) {
    // NOTHING
}

void squaring(int *a, int n) {
    // NOTHING
}
*/