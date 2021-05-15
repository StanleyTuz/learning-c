/* 
    Exercise 1-10: Write a program to copy its input to its output, replacing
        each tab by \t, each backspace by \b, and each backslash by \\. This 
        makes tabs and backspaces visible in an unambiguous way.

    I don't know what the integer representations of these characters are.
    We can easily find out. See the commented lines for an example. Instead
    of hard-coding these in, I will assign their values to variables so that
    this should work on arbitrary systems.
*/

#include <stdio.h>

int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }

    return 0;
}