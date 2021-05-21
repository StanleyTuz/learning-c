#include <stdio.h>
   /* count characters in input */
int main()
{
    int c;
    float lc;
    
    // printf("%d\n", 3);
    // printf("%d\n", '3');
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++lc;
    }
    printf("%.0f\n", lc);

    return 0;
}