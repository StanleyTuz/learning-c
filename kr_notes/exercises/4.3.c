/*
    Exercise 4-3: Given the basic framework, it's straightforward to extend 
        the calculator. Add the modulus (%) operator and provisions for 
        negative numbers.

    To do the modular division, we just cast both operands as ints before
        applying the C operator %.

    For negative numbers, the built-in operators will suffice. However, we
        need to be careful when reading in negative numbers, so that we don't
        interpret the sign as a subtraction operator. Basically when we read in
        a subtraction sign, we must also read the next character. If the next
        character is a digit, then we know it's a negative number. If not, we
        push the next character to the buffer and return the subtraction
        operator.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE  100     // operand stack
#define MAX_OP_SIZE 100     // operand string buffer (holds a single number)
#define BUFFER_SIZE 100     // buffer for ungetch
#define NUMBER      '0'     // indicate a number was returned

// define stack globally
double stack[STACK_SIZE];
int sp = 0; // stack pointer (next free position)

char buffer[BUFFER_SIZE];
int bufp = 0;

int getop(char []); // get operand from string repn
char getch(void);   // get a char from stdin
void ungetch(char); // "unget" a char (push to buffer)

void push(double);  // push operand (number) to stack
double pop(void);   // pop operand from stack

/* actual calculator logic is in main */
int main()
{
    int type;
    double temp;
    char operand[MAX_OP_SIZE];

    while((type = getop(operand)) != EOF) // get next op, store in `operand`
    {
        switch(type) {
            case NUMBER:    // push a number
                push(atof(operand));
                break;
            case '+':       // addition
                push(pop() + pop());
                break;
            case '-':       // subtraction
                temp = pop();
                push(pop() - temp);
                break;
            case '*':       // multiplication
                push(pop() * pop());
                break;
            case '/':       // division
                temp = pop();
                if (temp != 0.0)
                    push(pop() / temp);
                else
                    printf("Error: zero divisor!\n");
                break;
            case '%':
                temp = pop();
                if (temp != 0.0)
                    push(((int) pop()) % ((int)temp));
                break;
            case '\n':      // end input
                printf("\tresult: %.8g\n", pop());
                break;
            default:        // error
                printf("Error: unknown input %s\n", operand);
                break;
        }
    }
    return 0;
}


/* 
    Get the next operand or operator from the string, store
    the string in s[]. It may be an operator or a number, and
    the number may have multiple digits and a decimal.

    Returns a type code: NUMBER='0' if numeric, '+' if '+', etc.
*/
int getop(char s[])
{
    int i, c;

    // ignore leading whitespace
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0'; // currently s = ' \0'

    // currently holding a non-space character
    if (!isdigit(c) && c != '.') // it is an operand
    {   
        if(c == '-') // special handling for subtraction sign
        {
            if(isdigit(c = getch())) // negative number
            {
                s[0] = '-';
                ungetch(c);
            }
            else // this is a subtraction operand
            {
                ungetch(c);
                return '-';
            }
        }
        else
        {
            return c;
        }
    }
    
    i = 0;
    if (isdigit(c))
        while( isdigit(s[++i] = c = getch()) ) // grab digits until done
            ;
    if (c == '.') // get fractional digits
        while( isdigit(s[++i] = c = getch()) )
            ;
    s[i] = '\0';

    // if we've read too far, we must push the last character back onto
    // the buffer so it can be read from again; it may be an operator!
    if (c != EOF) 
        ungetch(c);
    
    return NUMBER;
}

/* push number to stack */
void push(double f)
{
    if (sp < STACK_SIZE)
        stack[sp++] = f;
    else
        printf("Error: stack full!\n");
}

/* pop number from stack */
double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else 
    {   
        printf("Error: stack empty!\n");
        return 0.0;
    }
}

/*
    Get a character from stdin. If the buffer is already in use,
        then we want to pop whatever is in there first. Else, just
        read stdin as usual.
*/
char getch(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

/*

*/
void ungetch(char c)
{
    if (bufp >= BUFFER_SIZE)
        printf("Error: ungetch buffer full!\n");
    else
        buffer[bufp++] = c;
}