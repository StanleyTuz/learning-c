#include <stdio.h>
#define MAX_LEN 100
int my_getline(char buffer[])
{
    int idx = 0;
    char c;

    while((c = getchar()) != '\n')
        buffer[idx++] = c;
    buffer[idx] = '\0';
    return idx;
}


void to_lower(char string[])
{
    int i = 0;
    // while ( string[i] != '\0' )
    for (int i = 0; string[i] != '\0'; ++i)
        string[i] = (string[i] >= 'A' && string[i] <= 'Z') ? string[i]-'A' + 'a' : string[i];
}

int main()
{
    // get a line
    char buffer[MAX_LEN];

    my_getline(buffer);

    printf("original: %s\n", buffer);

    to_lower(buffer);
    
    printf("final:    %s\n", buffer);
}