#include <stdio.h>
#define NMAX 10

int input(int *a);
void print(int *a);
void sort(int *a);

int main() {
    int data[NMAX];
    if (input(data) == 0) {
        sort(data);
        print(data);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {
    int flag = 1;
    char str;
    int count = 0;

    for (int i = 0; i < NMAX; i++) {
        if (i == NMAX - 1) {
            if (((scanf("%d%c", &a[i], &str)) == 2) && (str == '\n')) {
                count++;
            }
        } else if (((scanf("%d%c", &a[i], &str)) == 2) && (str == ' '))
            count++;
    }
    if (count == 10) {
        flag = 0;
    }
    return flag;
}
void print(int *a) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d ", a[i]);
    }
}
void sort(int *a) {
    int buffer;
    for (int i = 0; i < NMAX - 1; i++) {
        for (int j = i + 1; j < NMAX; j++) {
            if (a[i] > a[j]) {
                buffer = a[i];
                a[i] = a[j];
                a[j] = buffer;
            }
        }
    }
}

/*
    int flag = 1;
    char str;
    int count = 0;

    for (int i = 0; i < NMAX; i++) {
        if (i == NMAX - 1) {
            if (((scanf("%d%c", &a[i], &str)) == 2) && (str == '\n')) {
                count++;
            }
        } else if (((scanf("%d%c", &a[i], &str)) == 2) && (str == ' ')) count++;
    }
        if(count == 10) {
                flag = 0;
        }
    return flag;
*/
