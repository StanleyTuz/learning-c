/*
    Exercise 2-4: Write an alternative version of squeeze(s1,s2) that deletes 
        each character in s1 that matches any character in the string s2.
*/

#include <stdio.h>

int isin(char c, char s[]);
void squeeze(char s1[], char s2[]);


int isin(char c, char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (c == s[i])
            return 1;
        ++i;
    }
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; ++i)
    {
        if(isin(s1[i], s2) == 0)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}


int main()
{
    char s1[] = "hello there";
    char s2[] = "lh";

    printf("%s\n", s1);
    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}