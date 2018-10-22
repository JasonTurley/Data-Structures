/*
 * Driver file
 */
#include <stdio.h>

#include "stack.h"

int main()
{
    stack_t *s = stack_create();
    printf("s->size = %d\n", s->size);

    return 0;
}
