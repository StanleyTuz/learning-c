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

    for(i = 0; s[i] != '\0'; ++i)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if ( k > 0 && t[k] == '\0') // we made it all the way through the pattern
            return i;
    }
    return -1;
}



int main()
{
    char line[MAX_LINE];
    char pattern[] = "ould";
    int found = 0;

    while( getline2(line, MAX_LINE) > 0)
        if (strindex(line, pattern) != -1)
        {
            printf("%s", line);
            found++; 
        }
    return found;
}