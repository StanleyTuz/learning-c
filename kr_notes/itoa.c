#include <stdio.h>
#define BUFFER_SIZE    100  

void my_reverse(char s[])
{
    // get the length of s
    int s_len = 1;
    while (s[s_len] != '\0')
        ++s_len;

    // create a new string
    char t[BUFFER_SIZE];
    for (int i = 0; i < s_len; ++i)
        t[i] = s[s_len-1 - i];

    // replace s in-place
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        ++i;
}


void itoa(int n, char s[])
{
    int i, sign;

    if((sign = n) < 0) 
        n = -n;

    i = 0;
    do {
        s[i++] = n % 10 + '0'; // grab least sig digit
    } while((n /= 10) > 0); // do the division
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    my_reverse(s);
}


int main()
{
    char s[BUFFER_SIZE]; // = "12345";
    int n;

    // printf("%s\n", s);
    // my_reverse(s);
    // printf("%s\n", s);
    n = 210;
    itoa(n, s);
    printf("n: %d\ns: %s\n", n, s);

    return 0;
}