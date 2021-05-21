#include <stdio.h>
#define MAX_SIZE    25


void atoi_recursive(int n, char s[])
{
    static int i = 0;

    if (n < 0)
    {
        n = -n;
        s[i++] = '-';
    }
    if ( n / 10 ) // there are more significant digits
        atoi_recursive(n / 10, s);
    s[i++] = n % 10 + '0';
    s[i] = '\0'; // in case this is the last
}



int main()
{
    char s[MAX_SIZE];

    atoi_recursive(-12346, s);
    
    printf("The number is %s!\n", s);

    return 0;
}