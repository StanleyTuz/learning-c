/* 
    Exercise 1-19: Write a function reverse(s) that reverses the character 
    string s. Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAXLEN 10000

void my_reverse(char s[])
{
    // get the length of s
    int s_len = 1;
    while (s[s_len] != '\0')
        ++s_len;

    // create a new string
    char t[MAXLEN];
    for (int i = 0; i < s_len; ++i)
        t[i] = s[s_len-1 - i];

    // replace s in-place
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        ++i;
}


int main()
{
    char example[MAXLEN];
    char c = '0';

    // instead, use getline(example, MAXLEN)
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        example[i] = c;
        ++i;
    }
    example[i] = '\0';

    printf("original string: %s\n", example);
    my_reverse(example);
    printf("reversed string: %s\n", example);
    return 0;
}

