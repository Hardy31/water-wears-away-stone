#include <stdio.h>
 
void twice(int n, int *p)
{
    for(int i=0; i<n; i++)
    {
        *p= *p * 2; // увеличиваем значение по указателю
        p = p + 1; // перемещаем указатель на следующий элемент
    }
}
int main(void)
{
    int nums[] = {1, 2, 3, 4, 5};
    int length = 5;
     
    twice(length, nums);
     
    for(int i=0; i<length; i++)
    {
        printf("%d \t", nums[i]);
    }
     
    return 0;
}