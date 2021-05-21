/* 
    Exercise 1-8: Write a program to count blanks, tabs, and newlines.

    I assume all input is passed through stdin, i.e., getchar.
*/

#include <stdio.h>

int main()
{
    int bc, tc, nc;
    int c;

    for (bc = tc = nc = 0; (c = getchar()) != EOF;)
    {
        if (c == ' ')
            ++bc;
        else if (c == '\t')
            ++tc;
        else if (c == '\n')
            ++nc;
    }
    printf("%d blanks, %d tabs, %d newlines\n", bc, tc, nc);

    return 0;
}