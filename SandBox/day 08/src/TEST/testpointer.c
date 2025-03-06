#include <stdio.h>
 
void increment(int *x)
{
    *x = *x +1;
    printf("increment function: %d \n", *x);
}
 
int main(void)
{
    int n = 10;
    increment(&n);
    printf("main function: %d \n", n);
    return 0;
}