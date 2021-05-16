/*
    Exercise 2-7: Write a function invert(x,p,n) that returns x with the n bits 
    that begin at position p inverted (i.e., 1 changed into 0 and vice versa), 
    leaving the others unchanged.
*/

#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n)
{
    // mask out the range we want
    unsigned int mask = ~(~0 << n) << (p-n);

    return x ^ mask;
}


int main()
{
    unsigned int x = 0b01010101;
    printf("%ud\n", x);
    x = invert(x, 5,3);
    printf("%ud\n", x);

    return 0;
}