/* getch.c
    Includes getch buffer and functions.
*/
#include <stdio.h>
#define BUFFER_SIZE 100     // buffer for ungetch
char buffer[BUFFER_SIZE];
int bufp = 0;

/*
    Get a character from stdin. If the buffer is already in use,
        then we want to pop whatever is in there first. Else, just
        read stdin as usual.
*/
char getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

/*

*/
void ungetch(char c)
{
    if (bufp >= BUFFER_SIZE)
        printf("Error: ungetch buffer full!\n");
    else
        buffer[bufp++] = c;
}