/* stack.c
    Contains definitions of stack stuff.
*/

#include <stdio.h>
#include "calc.h"
#define STACK_SIZE 100

int sp = 0;
double stack[STACK_SIZE];

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