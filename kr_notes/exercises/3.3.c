/*
    Exercise 3-3: Write a function expand(s1,s2) that expands shorthand 
        notations like a-z in the string s1 into the equivalent complete 
        list abc...xyz in s2. Allow for letters of either case and digits, 
        and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. 
        Arrange that a leading or trailing - is taken literally.
*/

#include <stdio.h>
#define MAX_LINE    1000

void expand(char s1[], char s2[]);

int main()
{
    char input[MAX_LINE] = "a-z";
    char output[MAX_LINE];

    printf("%s\n", input);
    expand(input, output);
    printf("%s\n", output);
}


void expand(char s1[], char s2[])
{
    char prev = '\0';
    char mid = '\0';
    char next = '\0';
}