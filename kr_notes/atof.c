#include <stdio.h>

int isspace(char c)
{
    return (c == ' ' || c == '\t'); 
}

int isdigit(char c)
{
    return (c >= '0' || c <= '9'); 
}

float atof(char s[])
{
    double val, power;

    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        ++i;
    // digits to left of decimal
    for (val = 0.0; isdigit(s[i]); ++i)
    {
        val *= 10.0;
        val += s[i] - '0';
    }
    if (s[i] == '.')
        ++i;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val *= 10.0;
        val += s[i] - '0';
        power *= 10;
    }
    return sign * val / power;
}

int atoi(char s[])
{
    return (int)atof(s);
}