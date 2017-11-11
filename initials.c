#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  //toupper

#define IF_EQ(a, b) if(a == b)  // might as well practice macro usage
/**
 * 
 * Write, in a file called initials.c, a program that prompts a user for
 * their name and then outputs their initials in uppercase with no spaces 
 * or periods, followed by a newline (\n) and nothing more.
 * 
 **/

int main() 
{
    printf("Hi! What is your name?\n");
    // Store users name
    char name[30];
    fgets(name, 30, stdin);

    //print first character of first name
    printf("%c", toupper(name[0]));

    // Print first character of middle and or last names
    int i;
    size_t size = sizeof(name)/sizeof(name[0]);
    for (i = 0; i < size; i++)
    {
        // Space in name, next index is start of next name
        IF_EQ(name[i], ' ')
            printf("%c", toupper(name[i+1]));
    }

    puts("\n");

    return 0;
}