/*
    Exercise 3-2: Write a function escape(s,t) that converts characters like 
        newline and tab into visible escape sequences like \n and \t as it 
        copies the string t to s. Use a switch. Write a function for the other 
        direction as well, converting escape sequences into the real 
        characters.
*/
#include <stdio.h>
#define MAX_LINE    1000

void escape(char [], char []);
void my_getline(char []);


int main()
{
    char input[MAX_LINE];
    char output[MAX_LINE];

    my_getline(input);
    printf("input:  %s\n", input);

    escape(output, input);

    printf("output: %s\n", output);

    return 0;
}

void escape(char to[], char from[])
{
    int i, j;
    i = j = 0;
    while (from[i] != '\0')
    {
        switch (from[i]) 
        {
            case '\t':
                to[j++] = '\\';
                to[j++] = 't';
                break;
            case '\n':
                to[j++] = '\\';
                to[j++] = 'n';
                break;
            default:
                to[j++] = from[i];
        }
        ++i;
    }
    to[j] = '\0';
}


void my_getline(char to[])
{
    int i = 0;
    char c;
    while((c = getchar()) != '\n')
        to[i++] = c;
    to[i] = '\0';
}