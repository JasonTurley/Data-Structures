/*
 * @author jason
 * @date 10/21/18
 *
 * Implementation of a stack data structure.
 */

#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "stack.h"
#include "utils.h"


stack_t *stack_create(uint32_t max_size) 
{
    stack_t *s = safe_malloc(sizeof(stack_t));
    s->size = 0;
    s->capacity = max_size;
    s->elements = safe_malloc(sizeof(stack_t) * max_size);

    return s;
}

void push(stack_t *s, int data)
{
    assert(s);

    if (s->size > s->capacity) {
        resize(s);
    }

    s->elements[s->size++] = data;
}

int pop(stack_t *s)
{
    assert(s);

    if (s->size == 0) {
        printf ("Stack is empty\n");
        return INT_MIN;
    }

    int retval = s->elements[--(s->size)];;

    return retval;
}

int peek(stack_t *s)
{
    assert(s);

    return s->elements[s->size - 1];
}

void resize(stack_t *s)
{
    assert(s);

    uint32_t new_capacity = s->capacity * 2;
    s->elements = safe_realloc(s->elements, new_capacity);
    s->capacity = new_capacity;
}
