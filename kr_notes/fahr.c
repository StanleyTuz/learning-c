#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

/* print Fahrenheit-Celsius table */
int main()
{
    printf("Fahr   Celsius\n");
    for (float fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    {
        printf("%4.0f\t%6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));
    }

    return 0;
}