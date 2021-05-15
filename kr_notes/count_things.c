#include <stdio.h>

int main()
{
    int c;      /* digit counts */
    int i;
    int nwhite; /* white space counts */
    int nother; /* other count */
    int ndigit[10]; /* count each digit */

    /* initialize everything to zero */
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9') /* use character arithmetic */
        {
            ++ndigit[c-'0']; /* increment the appropriate bin */
        }
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("digits = ");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",
        nwhite, nother);
}