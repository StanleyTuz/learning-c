/*
    Exercise 5-2: Write getfloat, the floating-point analoog of getint. What
        type does getfloat returnn as its function value?

    getfloat still returns an int since we only use the return value for 
        conditional expressions. The function itself stores the float it grabs
        in a pointer variable's address.

    I am having some asssumed rounding issues when computing the fractional
        part of the floats. The code reads in the whole number part just as
        in the int case. If a decimal point is encountered, we enter a loop
        over any and all fractional decimal digits. These are added to *pn,
        but after they are divided by the appropriate factor of 10^n. This 
        division seems to make problems arise.

    Instead, we can just read in the entire number as if no decimal point,
        but keeping track of how many fractional digits there are. When we
        hit the end of the input, we can multiply this whole number by the
        appropriate factor. NOTE: doesn't fix the problem.
*/

#include <stdio.h>

#define SIZE            100
#define GET_BUF_SIZE    100

int buffer[GET_BUF_SIZE];
int bp = 0;

int getch();
void ungetch(int);

int getint(int *);
int getfloat(float *);
int isspace(int);
int isdigit(int);

int main()
{
    int n;
    float array[SIZE];

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        // ;
    {
        printf("Element %d is %f\n", n, array[n]);
    }


}


int getfloat(float *pn)
{
    int c;
    int sign;

    while(isspace(c = getch())) /* skip white space */
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    { // invalid char
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (isdigit(c))
    {
        for (*pn = 0; isdigit(c); c = getch()) // get whole number part
            *pn = 10 * *pn + (c - '0');
    }
    if (c == '.')
        c = getch();
    float power;
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
        power *= 10.;
    }
    *pn *= sign / power;
    if (c == EOF)
        ungetch(c);
    return c;
}

/* get integer from stdin into *pn */
int getint(int *pn)
{
    int c; /* accumulator */
    int sign;

    while(isspace(c = getch())) /* skip white space */
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-' )
    { /* oops - invalid char */
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if ( c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c == EOF)
        ungetch(c);
    return c;
}



int isspace(int c)
{
    return (c == ' ' || c == '\t');
}

int isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int getch()
{
    int c;
    if ( bp > 0 )
        c = buffer[bp--];
    else    
        c = getchar();
    return c; 
}

void ungetch(int c)
{
    if (bp < GET_BUF_SIZE)
        buffer[bp++] = c;
    else
        printf("Error: getch buffer is full!\n");
}