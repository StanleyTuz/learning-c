#include <stdio.h>

/* print Fahrenheit-Celsius table */
int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = -17.8;
    upper = 148.9;
    step = 17.8-6.7;

    fahr = lower;
    printf("Celsius     Fahr\n");
    while (fahr <= upper)
    {
        printf("%7.1f\t%8.1f\n", fahr, fahr * (9.0/5.0) + 32.0);
        fahr += step;
    }

    return 0;
}