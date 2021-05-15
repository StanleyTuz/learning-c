#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != EOF) /* EOF defined in stdio.h */
        putchar(c);
    
    // printf("%d", EOF);

    return 0;
}