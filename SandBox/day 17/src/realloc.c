#include <stdio.h>
#include <stdlib.h>

#define BLOCK 1

int main () {
    int input, count=1, i=1;
    int *data = (int*) malloc (count*BLOCK*sizeof(int));
    //int *startdata = data;
    int *current = data;
    while(scanf("%d", &input) && input != -1) {
        if (i%BLOCK == 0) {
            count++;
            data = (int*) realloc (data, count*BLOCK*sizeof(int));
            current = data + i - 1;
        }
        *current = input;
        printf("%d. [%p] => %d | COUNT = %d ||| ", i, current, *current, count);
        current++;
        i++;
    }
    
    printf("\n--------------------------\n");

    for (int j=0; j<i-1; j++) printf("%d ",data[j]);
    free(data);
    return 0;
}