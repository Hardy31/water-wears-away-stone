#include <stdio.h>

int main() {
    int p;
    for (int i=0; i<=4;i++) {
        scanf ("%d", &p);
        printf("%d | %d ", i, p);
        if (getchar() == '\n') break;
    } 
    return 0;
}