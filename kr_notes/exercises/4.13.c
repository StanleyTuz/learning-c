/*
    Exercise 4-13: Write a recursive version of the function reverse(s), which
        reverses the string s in place.

    I imagine we can do this by tracking the current position(s) within the
        string with a static variable, or with function parameters. Since
        static variables seem largely frowned upon, we will use parameters.

    This seems necessary since if we want to recursively swap elements, we 
        need to track which elements we are considering. Thus, we need to
        track state OR let the state be the inputs to the function. Hence,
        we will write a function reverse_recursive(char s[], int i, int j)
        where i and j are the characters under consideration.
*/

#include <stdio.h>

void swap(char s[], int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void reverse_recursive(char s[], int i, int j)
{
    if (s[j] == '\0')
        --j;
    
    if ( i == j )
        ;
    else if (i+1 == j)
    {
        swap(s, i, j);
    }
    else
    {
        swap(s, i, j);
        reverse_recursive(s, i+1, j-1);
    }
    return;
}





int main()
{
    char s[] = "!dekrow tI";
    printf("Original string:  %s\n", s);
    reverse_recursive(s, 0, 9); // j is last non-null char
    printf("Resulting string: %s\n", s);

    return 0;
}