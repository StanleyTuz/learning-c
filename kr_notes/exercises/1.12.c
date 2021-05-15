/*
    Exercise 1-12: Write a program that prints its input one word per line.

    Recall that we wrote 1.9.c to track blanks. We can easily adapt that 
    program to do this.
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
            else // we are starting a new word
            {
                blank_state = OUT_BLANK; // set to blank state
                putchar('\n');
                putchar(c);  
            }
        }
    }
    
    return 0;
}