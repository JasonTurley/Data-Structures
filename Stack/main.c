/*
 * Driver file
 */
#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main()
{
    stack_t *s = stack_create(10);
 
    pop(s);

    int i;
    for (i = 0; i < 12; i++) {
        push(s, i * 10);
    }

    int x = pop(s);
    printf("popped %d\n", x);

    return 0;
}
