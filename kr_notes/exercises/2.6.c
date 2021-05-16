/*
    Exercise 2-6: Write a function setbits(x,p,n,y) that returns x with the n 
        bits that begin at position p set to the rightmost n bits of y, 
        leaving the other bits unchanged.
*/

#include <stdio.h>


unsigned setbits(unsigned x, int p, int n, unsigned y) // unsigned means uint
{
    unsigned int y_bits;
    unsigned int x_left, x_right;
    
    y_bits = (~(~0 << n) & y) << (p-n);

    x_left = (x >> p) << p;
    x_right = ~(~0 << (p-n)) & x;

    return x_left | x_right | y_bits;
}

int main()
{
    unsigned int x = 0b01010101;
    unsigned int y = 0b11111111;

    printf("x original: %ud\n", x);
    x = setbits(x, 5, 3, y);

    printf("x after: %ud\n", x);
    return 0;
}