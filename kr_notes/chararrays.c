#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void my_copy(char to[], char from[]);


/* print the longest input line */
int main()
{
    char longest_line[MAXLINE];
    char current_line[MAXLINE];

    int current_length;
    int longest_length;

    longest_length = 0;
    while( (current_length = my_getline(current_line, MAXLINE)) > 0 )
    {
        if (current_length > longest_length)
        {
            printf("copying %s", current_line);
            my_copy(longest_line, current_line);
            printf("result: %s", longest_line);
            longest_length = current_length;
        }
    }

    if (longest_length > 0)
        printf("%d\n", longest_length);
        // printf("longest line: %s", longest_line);
    return 0;
}



/* read a line into s, return its length */
int my_getline(char s[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0'; // always terminate with this
    return i;
}


/* copy a character array into another one */
void my_copy(char to[], char from[])
{
    int i = 0;
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}