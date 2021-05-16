/*
    Exercise 2-8: Write a function rightrot(x,n) that returns the value of the 
        integer x rotated to the right by n positions.
*/

#include <stdio.h>

#define NUM_BITS    8*(int)sizeof(unsigned int)

unsigned int rightrot(unsigned int x, int n)
{
    return (x << (NUM_BITS-n)) | (x >> n);
}

int main()
{
    int num_bytes = (int)sizeof(unsigned int);

    printf("There are %d bits in our numbers.\n", NUM_BITS);

    unsigned int x = 0b11110000;
    printf("%d\n", x);
    x = rightrot(x, 3);
    printf("%d\n", x);
    x = 0b00000001;
    x = rightrot(x, 2); // 2^31
    printf("%d\n", x);



    return 0;
}