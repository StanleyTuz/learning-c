/*
    Exercise 1-13: Write a program to print a histogram of the lengths of the
        words in its input. It is easy to draw the histogram with the bars 
        horizontal; a vertical orientation is more challenging.

    We will again need to use the same logic from 1-12 and 1-9 to 
    determine whether or not we are in a word. This time, though, we want to
    keep track of the word length.

    To draw a vertical repn, we would need to know the maximum count.
*/

#include <stdio.h>

#define MAXLEN      10
#define MAXCOUNT    10
#define IN_BLANK    0
#define OUT_BLANK   1

int main()
{
    int hist[MAXLEN];
    for (int i = 0; i<MAXLEN; i++)
        hist[i] = 0;

    char blank_state; /* 1 if blank, 0 else */
    char c;

    int current_word_length = 0;
    for (blank_state = OUT_BLANK; (c = getchar()) != EOF;)
    {
        if (c == ' ' || c == '\t') // we have hit blanks
        {
            if (blank_state == OUT_BLANK) // enter blank state
            {
                if (current_word_length > 0)
                    hist[current_word_length] += 1;
                current_word_length = 1;
                blank_state = IN_BLANK;
                // don't emit anything
            }
            else    // we are already in blank state
                ;
        }
        else // this is a non-blank character
        {
            if (blank_state == OUT_BLANK) // if not in blank state,
            {
                current_word_length += 1;
                putchar(c);
            }
            else // we are starting a new word
            {
                current_word_length = 0;
                blank_state = OUT_BLANK; // set to blank state
                putchar('\n');
                putchar(c);  
            }
        }
    }
    /* we might have ended on a word */
    if (current_word_length > 0)
        hist[current_word_length] += 1;

    /* output the histogram */
    // printf("length    count\n");
    // for (int i = 0; i < MAXLEN; ++i)
    //     printf("%5d   %5d\n", i, hist[i]);

    /* I'm just hard-coding it for now. */
    for (int row = MAXCOUNT; row >= 0; --row)
    {   
        printf("%2d | ", row);
        for (int col = 0; col < MAXLEN; ++col)
        {
            if (hist[col] == row) 
                printf(" x ");
            else if (hist[col] > row)
                printf(" | ");
            else
                printf("   ");
            printf("   ");
        }   
        putchar('\n');
    }
    
    printf("    ");
    for (int i = 0; i < MAXLEN; ++i)
        printf(" %3d ", i);


    return 0;
}
