/*
    Exercise 1-22: Write a program to ``fold'' long input lines into two or 
        more shorter lines after the last non-blank character that occurs 
        before the n-th column of input. Make sure your program does something 
        intelligent with very long lines, and if there are no blanks or tabs 
        before the specified column.
*/

#include <stdio.h>

#define MAX_LINE    20
#define BUFFER_SIZE 1000

void my_getline(char buffer[], int buffer_size)
{
    int i;
    char c;

    i = 0;
    while((c = getchar()) != '\n')
    {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}

void printline(char s[], int start, int end)
{
    for (int i = start; i < end; ++i)
        putchar(s[i]);
}

/*
    Print a line by appropriately breaking the line. When there are spaces in
        the line, we break the line at the last space before the nth character,
        thus each line is at most n characters long.
*/
void print_fold(char s[], int n)
{
    int latest_blank_position = 0;
    int latest_line_break_position = 0;
    int current_line_length = 0;
    int i = 0; // position in buffer

    char c;
    while((c = s[i]) != '\0')
    {
        if (c == '\n')
        {
            putchar('\n');
            current_line_length = 0;
            latest_blank_position = 0;
            latest_line_break_position = i;
        }
        else if (current_line_length == n)
        {
            // we need to break this line
            if (latest_blank_position > 0)
                ;
            else // no blanks on this line
            {
                printline(s, latest_line_break_position, current_line_length-1);
                putchar('\n');
                putchar(c);

                current_line_length = 0;
                latest_blank_position = 0;
                latest_line_break_position = i;
            }
        }

        ++i;
    }


}



int main()
{
    char buffer[BUFFER_SIZE];
    my_getline(buffer, BUFFER_SIZE);

    print_fold(buffer, MAX_LINE);

    return 0;
}