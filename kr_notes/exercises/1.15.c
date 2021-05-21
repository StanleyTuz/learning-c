/*
    Exercise 1-15: Rewrite the temperature conversion program of Section 1.2 to
        use a function for conversion.
*/

#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

float ftoc(float f)
{
    return((5.0/9) * (f - 32.0));
}

/* print Fahrenheit-Celsius table */
int main()
{
    printf("Fahr   Celsius\n");
    for (float fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    {
        printf("%4.0f\t%6.1f\n", fahr, ftoc(fahr));
    }

    return 0;
}