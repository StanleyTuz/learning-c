#include <stdio.h>
// #include "h1.h"
// #include "h2.h"

extern int age; 
extern void myfunc();

int main()
{
    myfunc();

    printf("My age is %d!\n", age);
    return 0;
}