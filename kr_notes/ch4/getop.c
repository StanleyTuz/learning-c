/* getop.c
    Contains only the getop() function.
*/

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* 
    Get the next operand or operator from the string, store
    the string in s[]. It may be an operator or a number, and
    the number may have multiple digits and a decimal.

    Returns a type code: NUMBER='0' if numeric, '+' if '+', etc.
*/
int getop(char s[])
{
    int i, c;
    // static int c = EOF;

    // ignore leading whitespace
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0'; // currently s = ' \0'

    // currently holding a non-space character
    if (!isdigit(c) && c != '.') // it is an operand
        return c;
    
    i = 0;
    if (isdigit(c))
        while( isdigit(s[++i] = c = getch()) ) // grab digits until done
            ;
    if (c == '.') // get fractional digits
        while( isdigit(s[++i] = c = getch()) )
            ;
    s[i] = '\0';

    // if we've read too far, we must push the last character back onto
    // the buffer so it can be read from again; it may be an operator!
    if (c != EOF) 
        ungetch(c);
    // alt: with internal static, c will persist
    
    return NUMBER;
}