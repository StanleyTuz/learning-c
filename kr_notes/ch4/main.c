#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAX_OP_SIZE 100

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
                    push(pop()/temp);
                else
                    printf("Error: zero divisor!\n");
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