/*
    Exercise 1-20. Write a program detab that replaces tabs in the input with
        the proper number of blanks to space to the next tab stop. Assume a 
        fixed set of tab stops, say every n columns. Should n be a variable or 
        a symbolic parameter?

    It will definitely be a symbolic parameter via #define macro.

    We will assume that input is being read character-by-character and process
    it this way (this is how we do it with C streams). The general idea I have
    is to keep track of the current position in the line we're in, modulo n.
    This way, when we hit a '\t' character we know exactly how many blank spaces
    to insert. When we hit a newline, we reset this position to 0. Thus, this 
    program will assume that each line of input is short enough to fit on a
    line of stdout.

    For example, if the tab width is 8 spaces, and we encounter a tab character
    at position (mod 8) 3, then we need to insert 8 - 3 = 5 blank spaces.
*/

#include <stdio.h>

#define TAB_WIDTH   5

/* 
    Insert n blank spaces to stdout.
*/
void putblank(int n)
{
    for (int i = 0; i < n; ++i)
        putchar(' ');
}

int main()
{
    int current_position;
    char c;

    current_position = 0;
    while((c = getchar()) != EOF)
    {
        if( c != '\t' && c != '\n')
        {
            putchar(c);
            current_position = (current_position + 1) % TAB_WIDTH;
        }
        else if (c == '\n')
        {
            putchar(c);
            current_position = 0;
        }
        else // must be '\t'
        {
            putblank(TAB_WIDTH - current_position);
            current_position = 0;
        }
    }

    return 0;
}


