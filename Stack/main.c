/*
 * Driver file
 */
#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main()
{
    stack_t *s = stack_create(10);
 
    printf("Is stack empty? %d\n", isEmpty(s));

    int i;
    for (i = 0; i < 15; i++) {
        push(s, i * 10);
    }

    printf("Is stack empty? %d\n", isEmpty(s));
    printf("stack size: %d\n", getSize(s));

    stack_destroy(s);

    return 0;
}
