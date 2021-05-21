/* 
    Exercise 1-9: Write a program to copy its input to its output, replacing
        each string of one or more blanks by a single blank.

    To do this, we need to track whether we are currently in a blank or not,
        and only ouput a single blank after we hit a non-blank character.

    K&R gives an example in the following subsection where they use #define 
    macros to identify state. I will do this as well, since it is pretty 
    nifty-looking.
*/

#include <stdio.h>

#define IN_BLANK    1
#define OUT_BLANK   0

int main()
{
    char blank_state; /* 1 if blank, 0 else */
    char c;

    for (blank_state = OUT_BLANK; (c = getchar()) != EOF;)
    {
        if (c == ' ' || c == '\t') // we have hit blanks
        {
            if (blank_state == OUT_BLANK) // enter blank state
                blank_state = IN_BLANK;
                // don't emit anything
            else    // we are already in blank state
                ;
        }
        else // this is a non-blank character
        {
            if (blank_state == OUT_BLANK) // if not in blank state,
                putchar(c);
            else
            {
                blank_state = OUT_BLANK; // set to blank state
                putchar(' ');
                putchar(c);  
            }
        }
    }
    
    return 0;
}