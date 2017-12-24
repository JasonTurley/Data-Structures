// Various string manipulation functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char str[])
{
   int size = strlen(str);
   int i;
   for (i = size; i > -1; i--)
   {
       printf("%c", str[i]);
    }
    puts("\n");
}

// Funtion to reverse a const string
// Since it is const and cannot be modified, create a temp copy
char *reverse_const_string(char *str)
{
    // declare variables
    int size, start, end;
    char temp, *ptr = NULL;

    size = strlen(str);
    *ptr = malloc(sizeof(char)*size-1);

}

// Driver function
int main(int argc, char *argv[])
{
    char string[] = "Hello";
    char str2[] = "Johhy Boy";
    reverse(str2);
    return 0;
}