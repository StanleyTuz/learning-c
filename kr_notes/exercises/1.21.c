/*
    Exercise 1-21: Write a program entab that replaces strings of blanks by 
        the minimum number of tabs and blanks to achieve the same spacing. 
        Use the same tab stops as for detab. When either a tab or a single 
        blank would suffice to reach a tab stop, which should be given 
        preference?

*/

#include <stdio.h>

#define TAB_WIDTH   8

void putchar_n(char c, int n)
{
    for (int i = 0; i < n; ++i)
        putchar(c);
}
void print_n(char c[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%s", c);
}

int main()
{
    int current_blank_length;
    char in_blank;
    char c;

    current_blank_length = 0;
    while ((c = getchar()) != EOF)
    {
        if ( c != ' ' && c != '\t' ) // non-blank
        {
            if (in_blank == 1) // we're leaving a blank
            {
                int num_tabs;
                int num_spaces;

                num_tabs = current_blank_length / TAB_WIDTH;
                num_spaces = current_blank_length % TAB_WIDTH;
                // putchar_n('\t', num_tabs);
                // putchar_n(' ', num_spaces);
                print_n("\\t", num_tabs);
                print_n(" ", num_spaces);

                // reset the blank variables
                in_blank = 0;
                current_blank_length = 0;
            }
            else // we're in a word
                ;

            // write the character
            putchar(c);
        }
        else // it's a blank character
        {
            in_blank = 1;
            if (c == '\t')
                current_blank_length += TAB_WIDTH;
            else
                current_blank_length += 1;
        }
    }

    return 0;
}