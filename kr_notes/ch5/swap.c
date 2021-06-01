#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a; // value of a
    *a = *b;
    *b = temp;
}


int main()
{
    int a = 3, b = 8;
    printf("a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}