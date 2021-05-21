/*
    Exercise 4-1: Write the function strindex(s,t) which returns the position 
        of the rightmost occurrence of t in s, or -1 if there is none.

    This requires only a small modification: instead of breaking as soon as
        we find a match, we just continue traversing the string and saving only
        the last match we find.
*/

#include <stdio.h>

#define MAX_LINE    1000

/* read in a line */
int getline2(char s[], int max_line_length)
{
    int i = 0;
    char c;

    while( (c = getchar()) != EOF && --max_line_length && c != '\n' )
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    
    return i;
}

/* return index of first instance of substring t in s */
int strindex(char s[], char t[])
{
    int i; // sweep over s
    int j; // sweep over substrings in s
    int k; // sweet over pattern, t
    int found = -1;

    for(i = 0; s[i] != '\0'; ++i)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if ( k > 0 && t[k] == '\0') // we made it all the way through the pattern
            found = i;
    }
    return found;
}



int main()
{
    char line[MAX_LINE];
    char pattern[] = "ould";
    int found = 0;
    int found_pos = 0;

    while( getline2(line, MAX_LINE) > 0)
        if ((found_pos = strindex(line, pattern)) != -1)
        {
            printf("%d: %s", found_pos, line);
            found++;
        }
    return found;
}