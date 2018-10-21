/*
 * Driver file
 */
#include <stdio.h>

#include "stack.h"

int main()
{
    stack_t *s = stack_create();
    printf("s->size = %d\n", s->size);

    push(s, 5);
    printf("s->size = %d\n", s->size);

    push(s, -2);
    printf("s->size = %d\n", s->size);
    printf("s->head = %d\n", s->head->data);

    return 0;
}
