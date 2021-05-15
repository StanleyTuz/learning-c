#include <stdio.h> /* standard library: i/o */

int main()
{
    printf("sizeof(char):         %3lu\n", sizeof(char)); 
    printf("sizeof(int):          %3lu\n", sizeof(int)); /* implementation dependent */
    printf("sizeof(int32_t):      %3lu\n", sizeof(int32_t)); /* fixed width */
    printf("sizeof(_Bool):        %3lu\n", sizeof(_Bool));
    printf("sizeof(unsigned int): %3lu\n", sizeof(unsigned int)); /* my compiler may permit uint, or not */
    printf("sizeof(short):        %3lu\n", sizeof(short));
    printf("sizeof(long):         %3lu\n", sizeof(long));
    printf("sizeof(float):        %3lu\n", sizeof(float));
    printf("sizeof(double):       %3lu\n", sizeof(double));

    return 0;
}