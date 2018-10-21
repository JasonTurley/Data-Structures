/*
 * @author jason
 * @date 10/21/18
 *
 * Implementation of a stack data structure.
 */

#include <stdlib.h>
#include <assert.h>

#include "stack.h"
#include "utils.h"

stack_t *stack_create() 
{
    stack_t *s = safe_malloc(sizeof(stack_t));
    s->data = NULL;
    s->size = 0;
    s->next = NULL;

    return s;
}

void push(stack_t *s, int data)
{
    assert(s);
    s->data = &data;
    s->size++;
}
