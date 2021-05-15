#include <stdio.h>

int main()
{
    // printf("%d\n", 3);
    // printf("%d\n", '3');

    printf("%d\n", '0');   /* d prints the (true) integer representation of the character */
    printf("%c\n", '0');   /* d prints the character (alphanumeric) representation */

    printf("%d\n", '0'+'2'); /* add two chars: add their underlying int repn; print the resulting int */
    printf("%d\n", '0'+2); /* add chars and int: add their underlying int repn; print the resulting int */
    printf("%c\n", '0'+2); /* same as above, but show the resulting char */


    /* this last arithmetic will depend upon the integer encoding scheme for the characters. Since the character 
        '2' is 2 away from '0', this will result in the character '2'. Thus, we can do "character arithmetic" on
        alphanumeric characters if we know the distances between them in the encoding. */
    
    printf("%c has encoding %d\n", 'a', 'a');
    printf("%c has encoding %d\n", 'z', 'z');
    printf("%c has encoding %d\n", 'A', 'A');
    printf("%c has encoding %d\n", 'Z', 'Z');

    printf("\n");

    /* we can use this, for example, to quickly convert from uppercase to
        lowercase. */
    int offset = 'A' - 'a';
    printf("The lowercase version of %c is %c\n", 'D', 'D' - offset);
    

    printf("%s\n", "0"); /* double quotes: this is a string, and it's a different beast than a char */


}