
#include <stdio.h>

#define SIZE            100
#define GET_BUF_SIZE    100

int buffer[GET_BUF_SIZE];
// int *bp = &buffer[0];
int bp = 0;
int getch();
void ungetch(int);

int getint(int *);
int isspace(int);
int isdigit(int);

int main()
{
    int n;
    int array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    // {
    //     printf("Element %d is %d\n", n, array[n]);
    // }


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