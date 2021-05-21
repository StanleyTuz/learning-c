/*
    Exercise 1-23: Write a program to remove all comments from a C program. 
        Don't forget to handle quoted strings and character constants properly. 
        C comments don't nest.

    I will approach this by reading the input character-by-character and
    tracking whether or not I'm in one of the two types of comments. If
    I reach a single-line comment, I can safely emit '\n' and proceed to
    the next line of input. If I reach a multi-line comment, I must traverse
    through the comment and track the state accordingly, since the multi-line
    comment may have code after it on the same line, or it may span multiple
    lines.
*/

#include <stdio.h>

#define BUFFER_SIZE 1000


int my_getline(char buffer[], int maxlen)
{
    int c, i;
    i = 0;
    while((c = getchar()) != '\n')
    {
        buffer[i++] = c; 
    }
    buffer[i] = '\0';

    return i;
}

int main()
{
    // track the comment state
    int in_ml_comment = 0; // in multi-line comment
   
    char buffer[BUFFER_SIZE];
    while (my_getline(buffer, BUFFER_SIZE) > 0)
    {
        // iterate through the line and print accordingly
        int i = 0;
        char c;
        char nextchar;
        int skipline = 0;

        while ((c = buffer[i]) != '\0')
        {
            if (in_ml_comment == 1) // if we're in a multi-line comment
            {
                if (c == '\n')
                    skipline = 1;
                if (c == '*')
                {
                    nextchar = getchar();
                    if (nextchar == '/') 
                        in_ml_comment = 0;
                        if (skipline == 1)
                            putchar('\n');
                }
            }
            else // if not in a multi-line comment
            {
                putchar(c);
            }
            ++i;
        }
    }
}  