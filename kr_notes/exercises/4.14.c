#include <stdio.h>

#define swap(t,x,y) { t temp = x; x = y; y = temp; }

int main()
{
    float a = 1234.11;
    float b = 32.09;
    printf("Floats before: %f\t%f\n", a, b);
    swap(float, a, b);
    // swap(type(a), a, b);
    printf("Floats after:  %f\t%f\n", a, b);


    char *pa, *pb;
    pa = "there!";
    pb = "Hello";
    printf("Strings before: %s %s\n", pa, pb);
    swap(char *, pa, pb);
    // swap(type(a), a, b);
    printf("Strings after:  %s %s\n", pa, pb);   


}